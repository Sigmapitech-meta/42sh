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

DEBUG_USED
void builtin_getenv(context_t *ctx)
{
    command_t *cmd = ctx->cmd;
    char *env_val;

    if (cmd->argc == 1) {
        EPRINTF("Not enough arguments.\n");
        ctx->status = EXIT_FAILURE;
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
    ctx->status = EXIT_KO;
}
