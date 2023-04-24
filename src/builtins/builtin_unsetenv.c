/*
** EPITECH PROJECT, 2023
** minishell_1
** File description:
** builtin_unsetenv.c
*/

#include <string.h>
#include <unistd.h>

#include "list.h"
#include "shell/shell.h"

#include "wololo/utils.h"
#include "wololo/write.h"

void builtin_unsetenv(context_t *ctx)
{
    int index;
    command_t *cmd = ctx->cmd;

    if (cmd->argc == 1) {
        W_ERROR_LINE_C("unsetenv: Too few arguments.");
        return;
    }
    for (int i = 1; i < cmd->argc; i++) {
        index = env_find(ctx->env, cmd->argv[i], strlen(cmd->argv[i]));
        if (index != W_SENTINEL)
            list_remove(ctx->env, index);
    }
}
