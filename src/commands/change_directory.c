/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** change_directory.c
*/

#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "base.h"

#include "shell/shell.h"
#include "utils/debug_mode.h"
#include "utils/sentinel.h"
#include "utils/cleanup.h"

static
void move_relative(context_t *ctx, char *relative_path)
{
    command_t *cmd = ctx->cmd;
    char target_path[PATH_MAX];
    char *old_dir;

    DEBUG("Solving rel path: [%s]", relative_path);
    if (!realpath(relative_path, target_path)) {
        ctx->status = EXIT_FAILURE;
        return perror(cmd->argv[1]);
    }
    old_dir = getcwd(ctx->prev_dir, 0);
    if (IS_SENTINEL(chdir(target_path))) {
        EPRINTF("%s: %s.\n", cmd->argv[1], strerror(errno));
        ctx->status = EXIT_FAILURE;
        return;
    }
    free(ctx->prev_dir);
    ctx->prev_dir = old_dir;
}

static
void move_to_home(context_t *ctx)
{
    command_t *cmd = ctx->cmd;
    AUTO_FREE char *abs_dir = NULL;
    char *home = getenv("HOME");

    if (!home) {
        EPRINTF("No $home variable set\n");
        ctx->status = EXIT_FAILURE;
        return;
    }
    if (cmd->argc != 2 || strlen(cmd->argv[1]) <= 2)
        return move_relative(ctx, home);
    abs_dir = path_concat(home, cmd->argv[1] + 2);
    if (abs_dir)
        move_relative(ctx, abs_dir);
}

void builtin_cd(context_t *ctx)
{
    command_t *cmd = ctx->cmd;
    char *target_path = cmd->argv[1];

    if (cmd->argc > 2) {
        EPRINTF("cd: Too many arguments.\n");
        ctx->status = EXIT_FAILURE;
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
