/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** builtin_exit.c
*/

#include <stdlib.h>
#include "epitech.h"
#include "printf_expansion.h"
#include "shell/shell.h"

void builtin_exit(context_t *ctx)
{
    unsigned char status;
    command_t *cmd = ctx->cmd;

    if (cmd->argc > 2) {
        eprintf("exit: Expression Syntax.");
        return;
    }
    if (cmd->argc == 1) {
        ctx->is_running = FALSE;
        return;
    }
    status = atoi(cmd->argv[1]);
    if (!status && cmd->argv[1][0] != '0') {
        eprintf("exit: Expression Syntax.");
        return;
    }
    ctx->status = status;
    ctx->is_running = FALSE;
}
