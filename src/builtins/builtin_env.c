/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** builtin_env.c
*/

#include <stdio.h>

#include "list.h"
#include "printf_expansion.h"
#include "shell/shell.h"

void builtin_env(context_t *ctx)
{
    list_node_t *node;

    if (ctx->cmd->argc > 1) {
        eprintf("env: Too many arguments.\n");
        return;
    }
    node = ctx->env->head;
    if (!node) {
        eprintf("env: No environment.\n");
        return;
    }
    while (node) {
        printf("%s\n", (char *)node->value);
        node = node->next;
    }
}
