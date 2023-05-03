/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** debug_builtins.c
*/

#include <stdlib.h>

#include "base.h"
#include "shell/shell.h"
#include "utils/debug_mode.h"

DEBUG_USED
void builtin_getenv(context_t *ctx)
{
    command_t *cmd = ctx->cmd;
    char *env_val;

    if (cmd->argc == 1) {
        EPRINTF("Not enough arguments.\n");
        return;
    }
    for (int i = 1; i < cmd->argc; i++) {
        env_val = getenv(cmd->argv[i]);
        printf("--- %s ---\n", cmd->argv[i]);
        if (!env_val)
            printf("No %s variable found.\n", cmd->argv[i]);
        else
            printf("%s\n", env_val);
    }
}

DEBUG_USED
void builtin_prev_dir(context_t *ctx)
{
    printf("-> %s\n", ctx->prev_dir);
}
