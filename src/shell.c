/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** shell.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

#include "base.h"

#include "shell/alias.h"
#include "shell/builtins.h"
#include "shell/shell.h"
#include "shell/utils.h"
#include "utils/debug_mode.h"
#include "utils/sentinel.h"

char *prepars(context_t *ctx);

bool_t shell_read_line(context_t *ctx)
{
    ctx->input_size = get_line(&ctx->user_input);
    DEBUG("[%d] characters entered", ctx->input_size);
    if (IS_SENTINEL_OF(ctx->input_size, size_t)) {
        if (errno == ENOMEM) {
            ctx->is_running = FALSE;
            ctx->status = EXIT_FAILURE;
            return FALSE;
        }
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
    if (!WCOREDUMP(ctx->status)) {//&& !WIFEXITED(ctx->status) && WIFSIGNALED(ctx->status)) {
        DEBUG("%i", ctx->status);
        ctx->status = ctx->status % 255 + 128;
        DEBUG("%i", ctx->status);
    }
    return ctx->status;
}

void shell_evaluate(context_t *ctx)
{
    char *checkpoint;
    char *copy;
    char *copy_ptr;
    char *user_input = prepars(ctx);

    copy = NULL_OR(user_input, strdup(user_input));
    copy_ptr = copy;
    copy = NULL_OR(copy, strtok_r(copy, ";", &checkpoint));
    while (copy && ctx->is_running) {
        ctx->cmd->argc = str_count_tok(copy, " \t");
        ctx->cmd->argv = str_split(copy, " \t");
        alias_resolve(ctx->aliases, ctx->cmd);
        DEBUG("Found %d arguments", ctx->cmd->argc);
        shell_evaluate_expression(ctx);
        copy = strtok_r(NULL, ";", &checkpoint);
        free(ctx->cmd->argv);
    }
    if (copy_ptr)
        free(copy_ptr);
    ctx->user_input = user_input;
}

void shell_run_from_ctx(context_t *ctx)
{
    ctx->aliases = alias_list_create();
    if (!ctx->aliases)
        return;
    DEBUG_MSG("Entering main loop.");
    while (ctx->is_running) {
        if (ctx->ran_from_tty)
            prompt_display();
        if (shell_read_line(ctx))
            shell_evaluate(ctx);
    }
    alias_list_destroy(ctx->aliases);
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
        .prev_dir = getcwd(NULL, 0),
        .user_input = NULL,
        .input_size = 0,
        .status = 0
    };

    if (!ctx.prev_dir)
        return EXIT_FAILURE;
    DEBUG_MSG_IF(ctx.ran_from_tty, "stdin is a tty");
    DEBUG("Running in [%s]", ctx.prev_dir);
    shell_run_from_ctx(&ctx);
    free(ctx.prev_dir);
    env_free(ctx.original_env);
    return ctx.status;
}
