/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** builtin_setenv.c
*/

#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "shell/builtins.h"
#include "shell/shell.h"

#include "printf_expansion.h"
#include "utils/sentinel.h"

static
void command_run_env(context_t *ctx)
{
    command_t *cmd = ctx->cmd;

    cmd->argv[0] = "env";
    cmd->argv[1] = NULL;
    command_run_subprocess(ctx);
}

static char *get_env_setter(command_t *cmd)
{
    char *key = cmd->argv[1];
    char *val = cmd->argv[2];
    int size = strlen(key) + strlen(val) + 1;
    char *setter = calloc((size + 1), sizeof (char));

    if (!setter)
        return NULL;
    strncat(setter, key, size);
    strncat(setter, "=", size);
    strncat(setter, val, size);
    return setter;
}

void builtin_setenv(context_t *ctx)
{
    command_t *cmd = ctx->cmd;
    char *env_setter;

    if (cmd->argc == 1)
        return command_run_env(ctx);
    if (cmd->argc > 3) {
        eprintf("setenv: Too many arguments.\n");
        return;
    }
    env_setter = get_env_setter(cmd);
    if (!env_setter)
        return;
    if (putenv(env_setter) == W_SENTINEL)
        printf("setenv: %s", strerror(errno));
}
