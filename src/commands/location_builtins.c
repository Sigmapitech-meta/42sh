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

void builtin_which(context_t *ctx)
{
    bool_t found = FALSE;
    command_t *cmd = ctx->cmd;
    char *cmd_name = cmd->argv[1];
    char *path = getenv("PATH");
    AUTOFREE char *cmd_path = NULL;

    for (int i = 0; i < BUILTIN_COUNT && !found; i++)
        found = !strncmp(cmd_name, BUILTINS[i].name, strlen(BUILTINS[i].name));
    if (found) {
        printf("%s: shell built-in command.\n", cmd_name);
        return;
    }
    if (!path)
        return;
    cmd_path = path_find_access(path, cmd_name);
    if (!cmd_path)
        eprintf("%s: Command not found.\n", cmd_name);
    else
        printf("%s\n", cmd_path);
}

static
void builtin_where_search(context_t *ctx, char *cmd_name)
{
    AUTOFREE char *path_copy = NULL;
    char *path = getenv("PATH");
    char *cmd_path = NULL;
    char *search_path;
    char *checkpoint;

    if (!path)
        return;
    path_copy = strdup(path);
    if (!path_copy)
        return;
    search_path = strtok_r(path_copy + 5, ":", &checkpoint);
    while (search_path) {
        if (cmd_path)
            free(cmd_path);
        cmd_path = path_concat(search_path, cmd_name);
        if (cmd_name && !access(cmd_path, F_OK))
            printf("%s\n", cmd_path);
        search_path = strtok_r(NULL, ":", &checkpoint);
    }
}

void builtin_where(context_t *ctx)
{
    command_t *cmd = ctx->cmd;
    char *cmd_name = cmd->argv[1];

    for (int i = 0; i < BUILTIN_COUNT; i++)
        if (!strncmp(cmd_name, BUILTINS[i].name, strlen(BUILTINS[i].name)))
            printf("%s is a shell built-in\n", cmd_name);
    builtin_where_search(ctx, cmd_name);
}
