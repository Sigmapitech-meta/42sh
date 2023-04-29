/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** location_builtins.c
*/

#include <stdlib.h>
#include <string.h>

#include "epitech.h"
#include "printf_expansion.h"
#include "shell/builtins.h"
#include "shell/shell.h"
#include "shell/utils.h"
#include "utils/autofree.h"

static
bool_t is_builtin(char *cmd_name)
{
    char *builtin_name;

    for (int i = 0; i < BUILTIN_COUNT; i++) {
        builtin_name = BUILTINS[i].name;
        if (!strncmp(cmd_name, builtin_name, strlen(builtin_name)))
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
    command_t *cmd = ctx->cmd;
    AUTOFREE char *cmd_path = NULL;
    char *path = getenv("PATH");

    if (cmd->argc < 2) {
        eprintf("which: Too few arguments.");
        return;
    }
    for (int i = 1; i < cmd->argc; i++) {
        if (is_builtin(cmd->argv[i]))
            printf("%s: shell built-in command.\n", cmd->argv[i]);
        if (!path)
            return;
        cmd_path = path_find_access(path, cmd->argv[i]);
        if (!cmd_path)
            eprintf("%s: Command not found.\n", cmd->argv[i]);
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
        eprintf("where: Too few arguments.");
        return;
    }
    for (int i = 0; i < cmd->argc; i++) {
        cmd_name = cmd->argv[i];
        if (is_builtin(cmd_name))
            printf("%s is a shell built-in\n", cmd_name);
        builtin_where_search(cmd_name);
    }
}
