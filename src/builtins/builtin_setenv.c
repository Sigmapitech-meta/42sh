/*
** EPITECH PROJECT, 2023
** minishell_1
** File description:
** builtin_setenv.c
*/

#include "epitech/base.h"
#include "shell/builtins.h"
#include "shell/command.h"
#include "shell/context.h"
#include "wololo/write.h"
#include "shell/environment.h"
#include "wololo/sentinel.h"

#include <unistd.h>
#include <stdlib.h>

static void env_set_value(list_t *env, command_t *cmd, char *new_val)
{
    int index = env_find(env, cmd->argv[1], str_len(cmd->argv[1]));
    list_node_t *node;

    if (index == W_SENTINEL) {
        list_append(env, new_val);
        return;
    }
    node = list_get_node(env, index);
    if (node)
        node->value = new_val;
}

static void env_create_value(list_t *env, command_t *cmd)
{
    int i = 0;
    int kv_size = str_len(cmd->argv[1]) + str_len(cmd->argv[2]) + 2;
    char *new_val = malloc(kv_size * sizeof (char));

    if (!new_val)
        return;
    for (; cmd->argv[1][i]; i++)
        new_val[i] = cmd->argv[1][i];
    new_val[i++] = '=';
    if (cmd->argv[2])
        for (int j = 0; cmd->argv[2][j]; j++)
            new_val[i + j] = cmd->argv[2][j];
    env_set_value(env, cmd, new_val);
}

void builtin_setenv(context_t *ctx)
{
    command_t *cmd = ctx->cmd;

    if (cmd->argc == 1) {
        builtin_env(ctx);
        return;
    }
    if (cmd->argc >= 3) {
        W_ERROR_LINE_C("setenv: Too many arguments.");
    }
    env_create_value(ctx->env, cmd);
    return;
}
