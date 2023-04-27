/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** my_fill_list.c
*/

#include <fcntl.h>

#include "shell/auto_completion.h"
#include "list.h"

list_t *my_get_bin_list(char *env)
{
    char **path = my_get_path(env);
    char **alias = my_get_alias();
    list_t *bins = list_create();

    if (!bins)
        return NULL;
    for (int i = 0; path[i]; i ++)
        if (!access(path[i], X_OK))
            list_append(bins, path[i]);
    for (int i = 0; alias[i]; i ++)
        list_append(bins, alias[i]);
    return bins;
}
