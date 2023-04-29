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
