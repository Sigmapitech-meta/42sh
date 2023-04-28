/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** command.c
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#include "shell/shell.h"
#include "shell/utils.h"

#include "utils/debug_mode.h"
#include "utils/sentinel.h"
#include "printf_expansion.h"
#include "utils/autofree.h"

char *command_get_full_path(char **params)
{
    char *path;
    char *target_path = params[0];
    AUTOFREE char *dir = NULL;

    if (target_path[0] == '/')
        return strdup(target_path);
    if (target_path[0] == '.') {
        dir = getcwd(NULL, 0);
        path = path_concat(dir, target_path);
    } else
        path = path_find_cmd(target_path);
    return path;
}

static void command_run_internal(context_t *ctx, char *cmd_path, char **env)
{
    command_t *cmd = ctx->cmd;
    char *last_arg = cmd->argv[cmd->argc - 1];
    char *binary_name = cmd->argv[0];

    if (last_arg[0] == '|' && !last_arg[1]) {
        eprintf("Invalid null command.\n");
        return;
    }
    DEBUG("running [%s]", cmd_path);
    execve(cmd_path, cmd->argv, env + 1);
    DEBUG_MSG("STOP");
    eprintf("%s: %s.", binary_name, strerror(errno));
    if (errno == ENOEXEC)
        eprintf(" Wrong Architecture.", binary_name, strerror(errno));
    eprintf("\n");
    exit(W_SENTINEL);
}

void command_run(context_t *ctx)
{
    command_t *cmd = ctx->cmd;
    AUTOFREE char *cmd_path = command_get_full_path(cmd->argv);

    if (!cmd_path)
        exit(W_SENTINEL);
    if (access(cmd_path, F_OK)) {
        eprintf("%s: Command not found.\n", cmd->argv[0]);
        exit(W_SENTINEL);
    }
    command_run_internal(ctx, cmd_path, environ);
}

bool_t command_run_subprocess(context_t *ctx)
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
    return status != 0;
}
