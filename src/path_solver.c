/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** path_solver.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "utils/debug_mode.h"
#include "utils/cleanup.h"
#include "base.h"

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
    char *rest;
    AUTOFREE char *p_copy = strdup(path);
    char *p_search = NULL_OR(p_copy, strtok_r(p_copy + 5, ":", &rest));
    char *cmd_path = path_concat((p_search) ? p_search : p_copy, cmd);

    while (cmd_path && access(cmd_path, F_OK)) {
        p_search = strtok_r(NULL, ":", &rest);
        if (!p_search)
            break;
        free(cmd_path);
        cmd_path = path_concat(p_search, cmd);
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
