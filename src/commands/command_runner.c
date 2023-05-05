/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** command.c
*/

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#include "base.h"
#include "shell/shell.h"
#include "shell/utils.h"

#include "utils/debug_mode.h"
#include "utils/sentinel.h"
#include "utils/autofree.h"

char *command_handle_home(char *target_path)
{
    char *path;
    char *dir = getenv("HOME");

    if (!dir) {
        EPRINTF("No $home variable set\n");
        return NULL;
    }
    dir = strdup(dir);
    if (!dir)
        return NULL;
    path = path_concat(dir, target_path + 2);
    if (!path)
        return NULL;
    return path;
}

char *command_get_full_path(char **params)
{
    char *path;
    char *target_path = params[0];
    AUTOFREE char *dir = NULL;

    if (target_path[0] == '/')
        return strdup(target_path);
    if (target_path[0] == '~') {
        path = command_handle_home(target_path);
    } else if (target_path[0] == '.') {
        dir = getcwd(NULL, 0);
        path = path_concat(dir, target_path);
    } else
        path = path_find_cmd(target_path);
    if (!path)
        return NULL;
    return path;
}

static void command_run_internal(context_t *ctx, char *cmd_path, char **env)
{
    command_t *cmd = ctx->cmd;
    char *last_arg = cmd->argv[cmd->argc - 1];
    char *binary_name = cmd->argv[0];

    if (last_arg[0] == '|' && !last_arg[1]) {
        EPRINTF("Invalid null command.\n");
        return;
    }
    DEBUG("running [%s]", cmd_path);
    execve(cmd_path, cmd->argv, env);
    DEBUG_MSG("STOP");
    EPRINTF("%s: %s.", binary_name, strerror(errno));
    if (errno == ENOEXEC)
        EPRINTF(" Wrong Architecture.");
    EPRINTF("\n");
    exit(SENTINEL);
}

void command_run(context_t *ctx)
{
    command_t *cmd = ctx->cmd;
    AUTOFREE char *cmd_path = command_get_full_path(cmd->argv);

    if (!cmd_path || access(cmd_path, F_OK)) {
        EPRINTF("%s: Command not found.\n", cmd->argv[0]);
        exit(SENTINEL);
    }
    command_run_internal(ctx, cmd_path, environ);
}

int command_run_subprocess(context_t *ctx)
{
    int status;
    pid_t pid = fork();

    DEBUG("PID [%d | %d]", pid, getpid());
    ctx->user_input[ctx->input_size - 1] = '\0';
    if (!pid)
        command_run(ctx);
    DEBUG("%d | WAIT START", pid);
    wait(&status);
    DEBUG("%d | WAIT STOP: %d", pid, status);
    if (status)
        status_show(status);
    return status;
}
