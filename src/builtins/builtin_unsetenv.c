/*
** EPITECH PROJECT, 2023
** minishell_1
** File description:
** builtin_unsetenv.c
*/

#include <string.h>
#include <stdlib.h>

#include "list.h"
#include "shell/shell.h"

#include "printf_expansion.h"
#include "utils/sentinel.h"

void builtin_unsetenv(context_t *ctx)
{
    int index;
    list_node_t *node;
    command_t *cmd = ctx->cmd;

    if (cmd->argc == 1) {
        eprintf("unsetenv: Too few arguments.\n");
        return;
    }
    for (int i = 1; i < cmd->argc; i++) {
        index = env_find(ctx->env, cmd->argv[i], strlen(cmd->argv[i]));
        if (index == W_SENTINEL)
            continue;
        node = list_get_node(ctx->env, index);
        if (node) {
            free(node->value);
            list_remove_node(ctx->env, node);
        }
    }
}
