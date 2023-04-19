/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** builtin_exit.c
*/

#include "epitech/bool.h"
#include "shell/command.h"
#include "shell/context.h"
#include "wololo/write.h"

#include <unistd.h>

void builtin_exit(context_t *ctx)
{
    command_t *cmd = ctx->cmd;

    if (cmd->argc > 2) {
        W_OUTPUT_LINE_C("exit: Expression Syntax.");
        return;
    }
    ctx->is_running = FALSE;
}
