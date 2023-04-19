/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** builtins.c
*/

#include <string.h>

#include "epitech.h"

#include "shell/builtins.h"
#include "shell/shell.h"

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
