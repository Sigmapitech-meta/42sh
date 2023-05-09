/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** builtins.c
*/

#include <stdlib.h>
#include <string.h>

#include "base.h"
#include "epitech.h"

#include "shell/builtins.h"
#include "shell/shell.h"
#include "utils/debug_mode.h"

void builtin_exit(context_t *ctx)
{
    command_t *cmd = ctx->cmd;
    unsigned char status = (cmd->argc == 2) ? atoi(cmd->argv[1]) : 0;
    bool_t fail = cmd->argc > 2;

    fail |= ((!status && cmd->argc == 2 && cmd->argv[1][0] != '0'));
    if (fail)
        EPRINTF("exit: Expression Syntax.\n");
    else
        ctx->is_running = FALSE;
    ctx->status = status | fail;
}

void builtin_echo(context_t *ctx)
{
    command_run_subprocess(ctx);
}

int get_builtin_id(char *cmd_name)
{
    for (int i = 0; i < BUILTIN_COUNT; i++)
        if (!strcmp(cmd_name, BUILTINS[i].name))
            return i;
    return SENTINEL;
}

bool_t builtins_check(context_t *ctx)
{
    command_t *cmd = ctx->cmd;
    int i;

    if (!cmd->argc || !cmd->argv[0])
        return FALSE;
    i = get_builtin_id(cmd->argv[0]);
    if (IS_SENTINEL(i))
        return FALSE;
    DEBUG("Executing [%s] built-in", BUILTINS[i].name);
    BUILTINS[i].handler(ctx);
    return TRUE;
}
