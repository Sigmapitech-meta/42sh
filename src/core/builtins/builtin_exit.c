/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** builtin_exit.c
*/

#include <unistd.h>

#include "epitech.h"
#include "shell/shell.h"
#include "wololo/write.h"

void builtin_exit(context_t *ctx)
{
    command_t *cmd = ctx->cmd;

    if (cmd->argc > 2) {
        W_OUTPUT_LINE_C("exit: Expression Syntax.");
        return;
    }
    ctx->is_running = FALSE;
}
