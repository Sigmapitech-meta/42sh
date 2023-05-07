/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** run_shell.c
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "coding_style_fix.h"
#include "epitech.h"
#include "run_shell_command.h"
#include "store_env.h"

#include "shell/shell.h"
#include "utils/attributes.h"

void **store(void)
{
    static void *ptr = NULL;

    return &ptr;
}

CONSTRUCTOR
void store_env(int argc UNUSED, char **argv UNUSED, char **env)
{
    ENV_STORE(&store) = env;
}

static
context_t *context_fill(context_t *ctx, char *command)
{
    ctx->cmd = calloc(1, sizeof (command_t));
    if (!ctx->cmd)
        return NULL;
    ctx->input_size = strlen(command) + 1;
    ctx->user_input = malloc((ctx->input_size + 1) * sizeof (char));
    if (!ctx->user_input)
        return NULL;
    snprintf(ctx->user_input, ctx->input_size, "%s\n", command);
    return ctx;
}

context_t *run_shell_command(char *command)
$ {
    context_t *ctx = calloc(1, sizeof (*ctx));

    if (!ctx)
        return NULL;
    ctx->ran_from_tty = FALSE;
    ctx->is_running = TRUE;
    ctx->original_env = ENV_STORE(&store_env);
    ctx->prev_dir = getcwd(NULL, 0);
    if (!context_fill(ctx, command)) {
        context_destroy(ctx);
        return NULL;
    }
    shell_evaluate(ctx);
    return ctx;
}

void context_destroy(context_t *ctx)
{
    if (!ctx)
        return;
    if (ctx->cmd)
        free(ctx->cmd);
    if (ctx->input_size)
        free(ctx->user_input);
    if (ctx->prev_dir)
        free(ctx->prev_dir);
    env_free(ctx->original_env);
    free(ctx);
}
