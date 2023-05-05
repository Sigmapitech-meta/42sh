/*
** EPITECH PROJECT, 2023
** my_get_path.c
** File description:
** to get the binaries
*/

#include "shell/auto_completion.h"
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

static int count_file(char *path)
{
    DIR *dir = opendir(path);
    struct dirent *L_dir = NULL;
    struct stat stats;
    int count = 0;
    AUTOFREE char *path_in_file = NULL;
    path = my_strcat(path, "/");
    path_in_file = strdup(path);
    if (!dir)
        return -84;
    for (L_dir = readdir(dir); L_dir != NULL; L_dir = readdir(dir)) {
        if (L_dir->d_name[0] == '.')
            continue;
        path_in_file = strdup(path);
        path_in_file = my_strcat(path_in_file, L_dir->d_name);
        stat(path_in_file, &stats);
        if (access(path, X_OK) == 0)
            count ++;
    }
    closedir(dir);
    return count;
}

static int my_fill_bins(char *path, char **bins, int index)
{
    DIR *dir = opendir(path);
    struct dirent *L_dir = NULL;
    char *path_in_file = my_strcat(path, "/");

    if (dir == NULL) {
        printf("couldn't open %s\n", path);
        return 0;
    }
    for (L_dir = readdir(dir); L_dir != NULL; L_dir = readdir(dir)) {
        if (L_dir->d_name[0] == '.')
            continue;
        path = strdup(path_in_file);
        path = my_strcat(path_in_file, L_dir->d_name);
        if (access(path, X_OK) == 0) {
            bins[index] = strdup(L_dir->d_name);
            index ++;
        }
    }
    return index;
}

char **my_get_path(char *paths)
{
    char **path = my_str_split(paths, ":");
    char **bins = NULL;
    int len = 0;

    for (int i = 0; path[i]; i ++)
        len += count_file(strdup(path[i]));
    bins = calloc(sizeof(char *), (len + 1));
    len = 0;
    if (bins == NULL)
        return NULL;
    for (int i = 0; path[i + 2] != NULL; i += 2)
        len += my_fill_bins(path[i], bins, len);
    return bins;
}
