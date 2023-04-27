/*
** EPITECH PROJECT, 2023
** Minishell
** File description:
** Interpreter
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "list.h"
#include "shell/shell.h"
#include "utils/debug_mode.h"
#include "utils/autofree.h"

char *path_concat(char *left, char *right)
{
    int i = 0;
    size_t new_size = strlen(left) + 1 + strlen(right);
    char *out = (char *)malloc((new_size + 1) * sizeof (char));

    if (!out)
        return NULL;
    for (; left[i]; i++)
        out[i] = left[i];
    out[i++] = '/';
    for (int j = 0; right[j]; j++)
        out[i + j] = right[j];
    out[new_size] = '\0';
    return out;
}

char *path_find_cmd(list_t *env, char *cmd)
{
    char *checkpoint;
    char *path = list_get(env, ENV_FIND_VAR(env, "PATH"));
    AUTOFREE char *cur_dir = NULL;
    AUTOFREE char *path_copy = strdup(path);
    char *search_path = strtok_r(path_copy + 5, ":", &checkpoint);
    char *cmd_path = path_concat(search_path, cmd);

    while (access(cmd_path, F_OK)) {
        search_path = strtok_r(NULL, ":", &checkpoint);
        if (!search_path)
            break;
        free(cmd_path);
        cmd_path = path_concat(search_path, cmd);
    }
    if (!search_path || !cmd_path) {
        cur_dir = getcwd(NULL, 0);
        cmd_path = path_concat(cur_dir, cmd);
        DEBUG("Defaulting path to %s", cmd_path);
    }
    return cmd_path;
}
