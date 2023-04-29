/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** builtin_env.c
*/

#include <stdio.h>

#include "list.h"
#include "printf_expansion.h"
#include "shell/shell.h"

void builtin_env(context_t *ctx)
{
    if (ctx->cmd->argc > 1) {
        eprintf("env: Too many arguments.\n");
        return;
    }
    if (!ctx->env->size) {
        eprintf("env: No environment.\n");
        return;
    }
    LIST_FOREACH(ctx->env, node)
        printf("%s\n", (char *)node->value);
}
