/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** builtin_unsetenv.c
*/

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "base.h"
#include "epitech.h"

#include "shell/shell.h"
#include "utils/sentinel.h"

void putenv_safe(char *key, char *value, char **original_env)
{
    char *env_setter;

    if (getenv(key))
        env_free_key(key, original_env);
    env_setter = env_get_setter(key, value);
    if (!env_setter)
        return;
    if (putenv(env_setter) == W_SENTINEL)
        printf("setenv: %s", strerror(errno));
}

static
void command_run_env(context_t *ctx)
{
    command_t *cmd = ctx->cmd;

    cmd->argv[0] = "env";
    cmd->argv[1] = NULL;
    command_run_subprocess(ctx);
}

static
bool_t is_valid_env_key_case(char *name)
{
    char *ptr = name;

    if (!isalpha(*ptr)) {
        eprintf("setenv: Variable name must begin with a letter.\n");
        return FALSE;
    }
    for (; *ptr && isalnum(*ptr); ptr++);
    if (*ptr)
        eprintf(
            "setenv: Variable name must contain alphanumeric characters.\n"
        );
    return !*ptr;
}

void builtin_setenv(context_t *ctx)
{
    command_t *cmd = ctx->cmd;

    if (cmd->argc == 1)
        return command_run_env(ctx);
    if (cmd->argc > 3) {
        eprintf("setenv: Too many arguments.\n");
        return;
    }
    if (!is_valid_env_key_case(cmd->argv[1]))
        return;
    putenv_safe(cmd->argv[1], cmd->argv[2], ctx->original_env);
}

void builtin_unsetenv(context_t *ctx)
{
    command_t *cmd = ctx->cmd;

    if (cmd->argc == 1) {
        eprintf("unsetenv: Too few arguments.\n");
        return;
    }
    for (int i = 1; i < cmd->argc; i++)
        if (unsetenv(cmd->argv[i]) == W_SENTINEL)
            eprintf("unsetenv: %s", strerror(errno));
}
