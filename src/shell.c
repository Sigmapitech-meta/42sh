/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** shell.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "epitech.h"
#include "list.h"

#include "shell/builtins.h"
#include "shell/shell.h"
#include "shell/utils.h"

#include "utils/debug_mode.h"
#include "utils/sentinel.h"


bool_t shell_read_line(context_t *ctx)
{
    ctx->input_size = get_line(&ctx->user_input);
    DEBUG("[%zu] characters entered", ctx->input_size);
    if (ctx->input_size == (size_t)W_SENTINEL) {
        if (isatty(STDIN_FILENO))
            printf("exit\n");
        ctx->is_running = FALSE;
        return FALSE;
    }
    if (ctx->input_size < 2)
        return FALSE;
    ctx->user_input[ctx->input_size - 1] = '\0';
    return TRUE;
}

void shell_evaluate_expression(context_t *ctx)
{
    if (!builtins_check(ctx)) {
        DEBUG("Running [%s] as command", ctx->user_input);
        if (command_run_subprocess(ctx) && !ctx->ran_from_tty)
            exit(1);
    }
}

void shell_evaluate(context_t *ctx)
{
    char *checkpoint;
    char *raw_inp = ctx->user_input;
    command_t *cmd = ctx->cmd;

    ctx->user_input = strtok_r(ctx->user_input, ";", &checkpoint);
    while (ctx->is_running && ctx->user_input) {
        cmd->argc = param_count(ctx->user_input);
        cmd->argv = malloc((cmd->argc + 1) * sizeof (char *));
        DEBUG("Found %d arguments", cmd->argc);
        param_fill(cmd->argv, ctx->user_input);
        cmd->argv[cmd->argc] = NULL;
        shell_evaluate_expression(ctx);
        ctx->user_input = strtok_r(NULL, ";", &checkpoint);
    }
    ctx->user_input = raw_inp;
}

void shell_run_from_ctx(context_t *ctx)
{
    DEBUG_MSG("Entering main loop.");
    while (ctx->is_running) {
        if (ctx->ran_from_tty)
            printf("$> ");
        if (shell_read_line(ctx))
            shell_evaluate(ctx);
    }
    free(ctx->user_input);
}

void shell_run_from_env(char **env)
{
    context_t ctx = {0};

    ctx.ran_from_tty = isatty(STDIN_FILENO);
    DEBUG_MSG_IF(ctx.ran_from_tty, "stdin is a tty");
    ctx.env = env_parse(env);
    DEBUG("Registered %d values withing env", ctx.env->size);
    ctx.is_running = TRUE;
    ctx.prev_dir = getcwd(NULL, 0);
    DEBUG("Running in [%s]", ctx.prev_dir);
    ctx.cmd = malloc(sizeof (command_t));
    shell_run_from_ctx(&ctx);
    free(ctx.env);
    free(ctx.prev_dir);
}
