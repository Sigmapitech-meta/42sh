/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** path.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "utils/debug_mode.h"
#include "utils/cleanup.h"

char *path_concat(char *left, char *right)
{
    size_t written;
    size_t new_size = strlen(left) + 1 + strlen(right) + 1;
    char *out = malloc(new_size * sizeof (char));

    if (!out)
        return NULL;
    written = snprintf(out, new_size, "%s/%s", left, right);
    if (++written == new_size)
        return out;
    free(out);
    return NULL;
}

char *path_find_access(char *path, char *cmd)
{
    AUTOFREE char *path_copy = strdup(path);
    char *search_path;
    char *checkpoint;
    char *cmd_path;

    if (!path_copy)
        return NULL;
    search_path = strtok_r(path_copy + 5, ":", &checkpoint);
    cmd_path = path_concat(search_path, cmd);
    while (cmd_path && access(cmd_path, F_OK)) {
        search_path = strtok_r(NULL, ":", &checkpoint);
        if (!search_path)
            break;
        free(cmd_path);
        cmd_path = path_concat(search_path, cmd);
    }
    if (!access(cmd_path, F_OK))
        return cmd_path;
    free(cmd_path);
    return NULL;
}

char *path_find_cmd(char *cmd)
{
    AUTOFREE char *cur_dir = NULL;
    char *path = getenv("PATH");
    char *cmd_path;

    if (!path)
        return NULL;
    cmd_path = path_find_access(path, cmd);
    if (!cmd_path) {
        cur_dir = getcwd(NULL, 0);
        cmd_path = path_concat(cur_dir, cmd);
        DEBUG("Defaulting path to %s", cmd_path);
    }
    return cmd_path;
}
