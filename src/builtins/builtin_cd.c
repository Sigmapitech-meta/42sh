/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** builtin_cd.c
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "list.h"

#include "shell/shell.h"
#include "shell/utils.h"

#include "printf_expansion.h"
#include "utils/debug_mode.h"
#include "utils/sentinel.h"
#include "utils/autofree.h"

static
void move_to_dir(context_t *ctx, char *dir)
{
    command_t *cmd = ctx->cmd;
    char *current_dir = getcwd(NULL, 0);

    if (chdir(dir) != W_SENTINEL) {
        free(ctx->prev_dir);
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

static
void move_to_home(context_t *ctx)
{
    int i = ENV_FIND_VAR(ctx->env, "HOME");
    char *new_dir = (char *)(list_get(ctx->env, i) + 5);

    if (i == W_SENTINEL) {
        eprintf("No $home variable set\n");
        return;
    }
    move_to_dir(ctx, new_dir);
}

static
void move_relative(context_t *ctx)
{
    AUTOFREE char *current_dir;
    AUTOFREE char *target_path;
    command_t *cmd = ctx->cmd;

    current_dir = getcwd(NULL, 0);
    target_path = path_concat(current_dir, cmd->argv[1]);
    move_to_dir(ctx, target_path);
}

void builtin_cd(context_t *ctx)
{
    command_t *cmd = ctx->cmd;
    char *target_path = cmd->argv[1];

    if (cmd->argc > 2) {
        eprintf("cd: Too many arguments.\n");
        return;
    }
    if (cmd->argc == 1 || !strcmp(target_path, "--"))
        return move_to_home(ctx);
    if (!strncmp(target_path, "/", 2))
        return move_to_dir(ctx, "/");
    if (!strcmp(target_path, "-"))
        return move_to_dir(ctx, ctx->prev_dir);
    DEBUG("moving to [%s]", target_path);
    if (!strncmp(target_path, "/", 1))
        move_to_dir(ctx, target_path);
    else
        move_relative(ctx);
}
