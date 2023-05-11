/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** location_builtins.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "base.h"
#include "epitech.h"
#include "shell/builtins.h"
#include "shell/shell.h"
#include "utils/cleanup.h"

static
void check_access(char *path, char *cmd_name)
{
    AUTO_FREE char *cmd_path = path_concat(path, cmd_name);

    if (!cmd_path)
        return;
    if (!access(cmd_path, F_OK))
        printf("%s\n", cmd_path);
}

void builtin_which_each(char *cmd, char *path)
{
    AUTO_FREE char *cmd_path = NULL;

    if (!IS_SENTINEL(get_builtin_id(cmd))) {
        printf("%s: shell built-in command.\n", cmd);
        return;
    }
    cmd_path = path_find_access(path, cmd);
    if (!cmd_path)
        EPRINTF("%s: Command not found.\n", cmd);
    else
        printf("%s\n", cmd_path);
}

void builtin_which(context_t *ctx)
{
    command_t *cmd = ctx->cmd;
    char *path = getenv("PATH");

    if (cmd->argc < 2) {
        EPRINTF("which: Too few arguments.\n");
        ctx->status = EXIT_FAILURE;
        return;
    }
    for (int i = 1; i < cmd->argc; i++)
        if (!path)
            EPRINTF("%s: Command not found.\n", cmd->argv[i]);
        else
            builtin_which_each(cmd->argv[i], path);
}

static
bool_t builtin_where_search(char *cmd_name)
{
    AUTO_FREE char *path_copy = NULL;
    char *path = getenv("PATH");
    char *search_path;
    char *checkpoint;

    if (!path)
        return FALSE;
    path_copy = strdup(path);
    if (!path_copy)
        return FALSE;
    search_path = strtok_r(path_copy + 5, ":", &checkpoint);
    while (search_path) {
        check_access(search_path, cmd_name);
        search_path = strtok_r(NULL, ":", &checkpoint);
    }
    return TRUE;
}

void builtin_where(context_t *ctx)
{
    char *cmd_name;
    command_t *cmd = ctx->cmd;

    if (cmd->argc < 2) {
        EPRINTF("where: Too few arguments.\n");
        ctx->status = EXIT_FAILURE;
        return;
    }
    ctx->status = 0;
    for (int i = 1; i < cmd->argc && !ctx->status; i++) {
        cmd_name = cmd->argv[i];
        if (!IS_SENTINEL(get_builtin_id(cmd_name)))
            printf("%s is a shell built-in\n", cmd_name);
        ctx->status = !builtin_where_search(cmd_name);
    }
}
