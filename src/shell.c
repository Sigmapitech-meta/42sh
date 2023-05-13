/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** shell.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

#include "base.h"

#include "shell/history.h"
#include "shell/alias.h"
#include "shell/builtins.h"
#include "shell/shell.h"
#include "utils/debug_mode.h"
#include "utils/sentinel.h"
#include "utils/cleanup.h"

char *prepars(context_t *ctx);

bool_t shell_read_line(context_t *ctx)
{
    ctx->input_size = get_line(&ctx->user_input);
    DEBUG("[%d] characters entered", ctx->input_size);
    if (IS_SENTINEL_OF(ctx->input_size, size_t)) {
        if (errno == ENOMEM)
            ctx->status = EXIT_FAILURE;
        if (ctx->ran_from_tty)
            printf("exit\n");
        ctx->is_running = FALSE;
        return FALSE;
    }
    if (ctx->input_size < MINIMAL_INPUT_CHECK)
        return FALSE;
    ctx->user_input[ctx->input_size - 1] = '\0';
    for (int i = 0; ctx->user_input[i]; i++)
        if (!isspace(ctx->user_input[i]) && ctx->user_input[i] != ';')
            return TRUE;
    return FALSE;
}

int shell_evaluate_expression(context_t *ctx)
{
    DEBUG_USED command_t *cmd = ctx->cmd;

    if (builtins_check(ctx))
        return ctx->status;
    DEBUG("Running [%s] as command", cmd->argv[0]);
    ctx->status = command_run_subprocess(ctx);
    if (ctx->status && !ctx->ran_from_tty)
        ctx->is_running = FALSE;
    if (ctx->status == SENTINEL_DETECT)
        ctx->status = EXIT_FAILURE;
    if (ctx->status == SEGFAULT)
        ctx->status = SEGFAULT_CORE_DUMP;
    return ctx->status;
}

void shell_evaluate(context_t *ctx)
{
    char *checkpoint;
    char *user_input = prepars(ctx);
    char *copy = NULL_OR(user_input, strdup(user_input));
    AUTO_FREE char *copy_ptr = copy;
    command_t *cmd = ctx->cmd;

    IS_USED_BY_AUTOFREE(copy_ptr);
    copy = NULL_OR(copy, strtok_r(copy, ";", &checkpoint));
    while (copy && ctx->is_running) {
        cmd->argc = str_count_tok(copy, " \t");
        cmd->argv = str_split(copy, " \t");
        alias_resolve(ctx->aliases, cmd);
        DEBUG("Found %d arguments", cmd->argc);
        shell_evaluate_expression(ctx);
        copy = strtok_r(NULL, ";", &checkpoint);
        free(cmd->argv);
    }
    ctx->user_input = user_input;
}

void shell_run_from_ctx(context_t *ctx)
{
    ctx->aliases = alias_list_create();
    if (!ctx->aliases)
        return;
    if (ctx->ran_from_tty)
        ctx->history = history_create();
    if (ctx->ran_from_tty && !ctx->history)
        return;
    DEBUG_MSG("Entering main loop.");
    while (ctx->is_running) {
        if (ctx->ran_from_tty)
            prompt_display();
        if (shell_read_line(ctx))
            shell_evaluate(ctx);
    }
    alias_list_destroy(ctx->aliases);
    history_destroy(ctx->history);
    free(ctx->user_input);
}

int shell_run_from_env(char **env)
{
    command_t cmd = { 0 };
    context_t ctx = {
        .is_running = TRUE,
        .ran_from_tty = isatty(GET_SOURCE_LOCATION->_fileno),
        .cmd = &cmd,
        .original_env = env,
        .user_input = NULL,
        .input_size = 0,
        .status = 0
    };

    DEBUG_MSG_IF(ctx.ran_from_tty, "stdin is a tty");
    DEBUG("Running in [%s]", getenv("PWD"));
    shell_run_from_ctx(&ctx);
    free(ctx.prev_dir);
    env_free(ctx.original_env);
    return ctx.status;
}
