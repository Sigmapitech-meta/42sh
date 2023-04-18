/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** builtin_cd.c
*/

#include <unistd.h>
#include <errno.h>

#include "epitech/base.h"
#include "shell/context.h"
#include "shell/command.h"
#include "shell/environment.h"
#include "wololo/write.h"
#include "wololo/sentinel.h"
#include "shell/utils.h"
#include "wololo/debug_mode.h"
#include "epitech/printf.h"

static void move_to_dir(context_t *ctx, char *dir)
{
    command_t *cmd = ctx->cmd;
    char *current_dir = getcwd(NULL, 0);

    if (chdir(dir) != W_SENTINEL) {
        ctx->prev_dir = current_dir;
        return;
    }
    if (errno == ENOTDIR) {
        w_printf(STDERR_FILENO, "%s: Not a directory.\n", cmd->argv[1]);
        return;
    }
    if (errno == EACCES) {
        w_printf(STDERR_FILENO, "%s: Permission denied.\n", cmd->argv[1]);
        return;
    }
    w_printf(STDERR_FILENO, "%s: No such file or directory.\n", cmd->argv[1]);
}

static void move_to_home(context_t *ctx)
{
    int i = ENV_FIND_VAR(ctx->env, "HOME");
    char *new_dir = (char *)(list_get(ctx->env, i) + 5);

    if (!new_dir) {
        W_ERROR_LINE_C("No $home variable set");
        return;
    }
    move_to_dir(ctx, new_dir);
}

void builtin_cd(context_t *ctx)
{
    command_t *cmd = ctx->cmd;

    if (cmd->argc > 2) {
        W_OUTPUT_LINE_C("cd: Too many arguments.");
        return;
    }
    if (cmd->argc == 1 || !str_compare(cmd->argv[1], "~", 2))
        return move_to_home(ctx);
    if (!str_compare(cmd->argv[1], "/", 2))
        return move_to_dir(ctx, "/");
    if (!str_compare(cmd->argv[1], "-", 2))
        return move_to_dir(ctx, ctx->prev_dir);
    DEBUG("moving to [%s]", cmd->argv[1]);
    if (!str_compare(cmd->argv[1], "/", 1))
        move_to_dir(ctx, cmd->argv[1]);
    else
        move_to_dir(ctx, path_concat(getcwd(NULL, 0), cmd->argv[1]));
}
