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
#include "shell/alias.h"

void builtin_exit(context_t *ctx)
{
    unsigned char status;
    command_t *cmd = ctx->cmd;

    if (cmd->argc > 2) {
        EPRINTF("exit: Expression Syntax.\n");
        return;
    }
    if (cmd->argc == 1) {
        ctx->is_running = FALSE;
        return;
    }
    status = atoi(cmd->argv[1]);
    if (!status && cmd->argv[1][0] != '0') {
        EPRINTF("exit: Expression Syntax.\n");
        return;
    }
    ctx->status = status;
    ctx->is_running = FALSE;
}

void builtin_echo(context_t *ctx)
{
    command_run_subprocess(ctx);
}

bool_t builtins_check(context_t *ctx)
{
    char *builtin_name;
    command_t *cmd = ctx->cmd;

    for (int i = 0; i < BUILTIN_COUNT; i++) {
        builtin_name = BUILTINS[i].name;
        if (!strcmp(cmd->argv[0], builtin_name)) {
            DEBUG("Executing [%s] built-in", BUILTINS[i].name);
            BUILTINS[i].handler(ctx);
            return TRUE;
        }
    }
    return FALSE;
}

void builtin_alias(context_t *ctx)
{
    char *out;
    char *offset;
    command_t *cmd = ctx->cmd;
    size_t len;

    if (cmd->argc == 1)
        return alias_list_print(ctx->aliases);
    if (cmd->argc == 2)
        return;
    offset = strstr(ctx->user_input, cmd->argv[2]);
    len = strlen(ctx->user_input);
    out = malloc((len + 1) * sizeof (char));
    snprintf(out, len + 1, "alias %s=%s", cmd->argv[1], offset);
    alias_add(ctx->aliases, out);
}
