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
#include "shell/utils.h"
#include "utils/cleanup.h"

static
bool_t is_builtin(char *cmd_name)
{
    for (int i = 0; i < BUILTIN_COUNT; i++) {
        if (!strcmp(cmd_name, BUILTINS[i].name))
            return TRUE;
    }
    return FALSE;
}

static void check_access(char *path, char *cmd_name)
{
    AUTOFREE char *cmd_path = path_concat(path, cmd_name);

    if (!cmd_path)
        return;
    if (!access(cmd_path, F_OK))
        printf("%s\n", cmd_path);
}

void builtin_which(context_t *ctx)
{
    AUTOFREE char *cmd_path = NULL;
    char *path = getenv("PATH");

    if (ctx->cmd->argc < 2) {
        EPRINTF("which: Too few arguments.\n");
        return;
    }
    for (int i = 1; i < ctx->cmd->argc; i++) {
        if (is_builtin(ctx->cmd->argv[i])) {
            printf("%s: shell built-in command.\n", ctx->cmd->argv[i]);
            return;
        }
        if (!path)
            return;
        cmd_path = path_find_access(path, ctx->cmd->argv[i]);
        if (!cmd_path)
            EPRINTF("%s: Command not found.\n", ctx->cmd->argv[i]);
        else
            printf("%s\n", cmd_path);
    }
}

static
void builtin_where_search(char *cmd_name)
{
    AUTOFREE char *path_copy = NULL;
    char *path = getenv("PATH");
    char *search_path;
    char *checkpoint;

    if (!path)
        return;
    path_copy = strdup(path);
    if (!path_copy)
        return;
    search_path = strtok_r(path_copy + 5, ":", &checkpoint);
    while (search_path) {
        check_access(search_path, cmd_name);
        search_path = strtok_r(NULL, ":", &checkpoint);
    }
}

void builtin_where(context_t *ctx)
{
    char *cmd_name;
    command_t *cmd = ctx->cmd;

    if (cmd->argc < 2) {
        EPRINTF("where: Too few arguments.\n");
        return;
    }
    for (int i = 0; i < cmd->argc; i++) {
        cmd_name = cmd->argv[i];
        if (is_builtin(cmd_name))
            printf("%s is a shell built-in\n", cmd_name);
        builtin_where_search(cmd_name);
    }
}
