/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** builtin_cd.c
*/

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "list.h"

#include "shell/shell.h"
#include "shell/utils.h"

#include "printf_expansion.h"
#include "utils/debug_mode.h"
#include "utils/sentinel.h"

static void move_to_dir(context_t *ctx, char *dir)
{
    command_t *cmd = ctx->cmd;
    char *current_dir = getcwd(NULL, 0);

    if (chdir(dir) != W_SENTINEL) {
        ctx->prev_dir = current_dir;
        return;
    }
    if (errno == ENOTDIR) {
        eprintf("%s: Not a directory.\n", cmd->argv[1]);
        return;
    }
    if (errno == EACCES) {
        eprintf("%s: Permission denied.\n", cmd->argv[1]);
        return;
    }
    eprintf("%s: No such file or directory.\n", cmd->argv[1]);
}

static void move_to_home(context_t *ctx)
{
    int i = ENV_FIND_VAR(ctx->env, "HOME");
    char *new_dir = (char *)(list_get(ctx->env, i) + 5);

    if (!new_dir) {
        eprintf("No $home variable set\n");
        return;
    }
    move_to_dir(ctx, new_dir);
}

void builtin_cd(context_t *ctx)
{
    command_t *cmd = ctx->cmd;

    if (cmd->argc > 2) {
        eprintf("cd: Too many arguments.\n");
        return;
    }
    if (cmd->argc == 1 || !strncmp(cmd->argv[1], "~", 2))
        return move_to_home(ctx);
    if (!strncmp(cmd->argv[1], "/", 2))
        return move_to_dir(ctx, "/");
    if (!strncmp(cmd->argv[1], "-", 2))
        return move_to_dir(ctx, ctx->prev_dir);
    DEBUG("moving to [%s]", cmd->argv[1]);
    if (!strncmp(cmd->argv[1], "/", 1))
        move_to_dir(ctx, cmd->argv[1]);
    else
        move_to_dir(ctx, path_concat(getcwd(NULL, 0), cmd->argv[1]));
}
