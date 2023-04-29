/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** builtins.c
*/

#include <stdlib.h>
#include <string.h>

#include "epitech.h"
#include "printf_expansion.h"

#include "shell/builtins.h"
#include "shell/shell.h"
#include "utils/debug_mode.h"

void builtin_exit(context_t *ctx)
{
    unsigned char status;
    command_t *cmd = ctx->cmd;

    if (cmd->argc > 2) {
        eprintf("exit: Expression Syntax.\n");
        return;
    }
    if (cmd->argc == 1) {
        ctx->is_running = FALSE;
        return;
    }
    status = atoi(cmd->argv[1]);
    if (!status && cmd->argv[1][0] != '0') {
        eprintf("exit: Expression Syntax.\n");
        return;
    }
    ctx->status = status;
    ctx->is_running = FALSE;
}

bool_t builtins_check(context_t *ctx)
{
    char *builtin_name;
    command_t *cmd = ctx->cmd;

    for (int i = 0; i < BUILTIN_COUNT; i++) {
        builtin_name = BUILTINS[i].name;
        if (!strncmp(cmd->argv[0], builtin_name, strlen(builtin_name))) {
            DEBUG("Executing [%s] built-in", BUILTINS[i].name);
            BUILTINS[i].handler(ctx);
            return TRUE;
        }
    }
    return FALSE;
}
