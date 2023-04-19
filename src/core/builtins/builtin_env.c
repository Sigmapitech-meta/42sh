/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** builtin_env.c
*/

#include <string.h>
#include <unistd.h>

#include "list.h"
#include "shell/shell.h"

#include "wololo/write.h"

void builtin_env(context_t *ctx)
{
    list_node_t *node;

    if (ctx->cmd->argc > 1) {
        W_ERROR_LINE_C("env: Too many arguments.");
        return;
    }
    node = ctx->env->head;
    if (!node) {
        W_ERROR_LINE_C("env: No environment.");
        return;
    }
    while (node) {
        write(STDOUT_FILENO, node->value, strlen(node->value));
        node = node->next;
        W_OUTPUT_C("\n");
    }
}
