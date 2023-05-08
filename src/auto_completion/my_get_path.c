/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** my_get_path.c
*/

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "shell/auto_completion.h"
#include "base.h"

static
int count_file(char *path)
{
    DIR *dir = opendir(path);
    struct dirent *l_dir = NULL;
    int count = 0;

    path = my_strcat(path, "/");
    if (!dir)
        return -84;
    for (l_dir = readdir(dir); l_dir; l_dir = readdir(dir)) {
        if (l_dir->d_name[0] == '.')
            continue;
        if (!access(path, X_OK))
            count++;
    }
    closedir(dir);
    return count;
}

static
int my_fill_bins(char *path, char **bins, int index)
{
    DIR *dir = opendir(path);
    struct dirent *l_dir = NULL;
    char *path_in_file = my_strcat(path, "/");

    if (!dir) {
        printf("couldn't open %s\n", path);
        return 0;
    }
    for (l_dir = readdir(dir); l_dir; l_dir = readdir(dir)) {
        if (l_dir->d_name[0] == '.')
            continue;
        path = my_strcat(path_in_file, l_dir->d_name);
        if (!access(path, X_OK)) {
            bins[index] = strdup(l_dir->d_name);
            index++;
        }
    }
    return index;
}

char **my_get_path(char *paths)
{
    char **path = str_split(paths, ":");
    char **bins = NULL;
    int len = 0;

    for (int i = 0; path[i]; i++)
        len += count_file(strdup(path[i]));
    bins = calloc(sizeof(char *), (len + 1));
    len = 0;
    if (!bins)
        return NULL;
    for (int i = 0; path[i + 2]; i += 2)
        len += my_fill_bins(path[i], bins, len);
    return bins;
}
