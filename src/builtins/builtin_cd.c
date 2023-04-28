/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** builtin_cd.c
*/

#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "list.h"
#include "shell/shell.h"

#include "printf_expansion.h"
#include "utils/debug_mode.h"
#include "utils/sentinel.h"
#include "utils/autofree.h"

static
void move_relative(context_t *ctx, char *relative_path)
{
    command_t *cmd = ctx->cmd;
    char target_path[PATH_MAX];

    DEBUG("Solving rel path: [%s]", relative_path);
    if (!realpath(relative_path, target_path))
        return perror(cmd->argv[1]);
    ctx->prev_dir = getcwd(ctx->prev_dir, 0);
    if (chdir(target_path) == W_SENTINEL)
        eprintf("%s: %s.\n", cmd->argv[1], strerror(errno));
}

static
char *concat_home(context_t *ctx, char *home)
{
    size_t len = strlen(home);
    char *abs_dir = calloc(len + strlen(ctx->cmd->argv[1]), sizeof(char));

    if (!abs_dir)
        return NULL;
    strcat(abs_dir, home);
    abs_dir[len] = '/';
    strcat(abs_dir, ctx->cmd->argv[1] + 2);
    return abs_dir;
}

static
void move_to_home(context_t *ctx)
{
    command_t *cmd = ctx->cmd;
    int i = ENV_FIND_VAR(ctx->env, "HOME");
    AUTOFREE char *abs_dir = NULL;
    char *home;

    if (i == W_SENTINEL) {
        eprintf("No $home variable set\n");
        return;
    }
    home = (char *)(list_get(ctx->env, i) + 5);
    if (cmd->argc != 2 || strlen(cmd->argv[1]) <= 2)
        return move_relative(ctx, home);
    abs_dir = concat_home(ctx, home);
    if (abs_dir)
        move_relative(ctx, abs_dir);
}

void builtin_cd(context_t *ctx)
{
    command_t *cmd = ctx->cmd;
    char *target_path = cmd->argv[1];

    if (cmd->argc > 2) {
        eprintf("cd: Too many arguments.\n");
        return;
    }
    if (
        cmd->argc == 1
        || !strncmp(target_path, "~", 1)
        || !strcmp(target_path, "--")
    )
        return move_to_home(ctx);
    if (!strcmp(target_path, "-"))
        return move_relative(ctx, ctx->prev_dir);
    DEBUG("moving to [%s]", target_path);
    move_relative(ctx, target_path);
}
