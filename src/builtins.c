/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** builtins.c
*/

#include "epitech/base.h"
#include "epitech/bool.h"
#include "epitech/list.h"

#include "shell/command.h"
#include "shell/context.h"
#include "shell/builtins.h"
#include "wololo/debug_mode.h"

const builtin_t BUILTINS[] = {
    {"cd", &builtin_cd},
    {"env", &builtin_env},
    {"exit", &builtin_exit},
    {"setenv", &builtin_setenv},
    {"unsetenv", &builtin_unsetenv},
};

const int BUILTIN_COUNT = CONST_ARR_SIZE(BUILTINS);

bool_t builtins_check(context_t *ctx)
{
    command_t *cmd = ctx->cmd;

    for (int i = 0; i < BUILTIN_COUNT; i++) {
        if (!STR_COMPARE_FIX(cmd->argv[0], BUILTINS[i].name)) {
            DEBUG("Executing [%s] built-in", BUILTINS[i].name);
            BUILTINS[i].handler(ctx);
            return TRUE;
        }
    }
    return FALSE;
}
