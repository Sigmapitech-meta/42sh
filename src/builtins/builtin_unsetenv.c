/*
** EPITECH PROJECT, 2023
** minishell_1
** File description:
** builtin_unsetenv.c
*/

#include "epitech/base.h"
#include "shell/context.h"
#include "shell/command.h"
#include "shell/environment.h"
#include "wololo/sentinel.h"
#include "wololo/write.h"

#include <unistd.h>

void builtin_unsetenv(context_t *ctx)
{
    int index;
    command_t *cmd = ctx->cmd;

    if (cmd->argc == 1) {
        W_ERROR_LINE_C("unsetenv: Too few arguments.");
        return;
    }
    for (int i = 1; i < cmd->argc; i++) {
        index = env_find(ctx->env, cmd->argv[i], str_len(cmd->argv[i]));
        if (index != W_SENTINEL)
            list_remove(ctx->env, index);
    }
}
