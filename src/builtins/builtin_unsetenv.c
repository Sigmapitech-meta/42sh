/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** builtin_unsetenv.c
*/

#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include "shell/shell.h"

#include "printf_expansion.h"
#include "utils/sentinel.h"

void builtin_unsetenv(context_t *ctx)
{
    command_t *cmd = ctx->cmd;

    if (cmd->argc == 1) {
        eprintf("unsetenv: Too few arguments.\n");
        return;
    }
    for (int i = 1; i < cmd->argc; i++)
        if (unsetenv(cmd->argv[i]) == W_SENTINEL)
            eprintf("unsetenv: %s", strerror(errno));
}
