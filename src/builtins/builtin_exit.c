/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** builtin_exit.c
*/

#include "epitech.h"
#include "printf_expansion.h"
#include "shell/shell.h"

void builtin_exit(context_t *ctx)
{
    command_t *cmd = ctx->cmd;

    if (cmd->argc > 2) {
        eprintf("exit: Expression Syntax.");
        return;
    }
    ctx->is_running = FALSE;
}
