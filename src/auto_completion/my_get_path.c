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

static int count_file(char *path)
{
    DIR *dir = opendir(path);
    struct dirent *L_dir = NULL;
    struct stat stats;
    int count = 0;
    char *save_path = NULL;

    strcat(path, "/");
    save_path = strdup(path);
    if (!dir)
        return -84;
    for (L_dir = readdir(dir); L_dir != NULL; L_dir = readdir(dir)) {
        printf("sol\n");
        printf("Now checking file %s\n", L_dir->d_name);
        path = strdup(save_path);
        stat(path, &stats);
       if (L_dir->d_name[0] == '.')
            continue;
        strcat(path, L_dir->d_name);
        if (access(path, X_OK) == 0) {
            printf("(%s) is a bin\n", L_dir->d_name);
            count ++;
        }
        free(path);
        printf("eol\n");
    }
    closedir(dir);
    return count;
}

static int my_fill_bins(char *path, char **bins, int *index)
{
    DIR *dir = opendir(path);
    struct dirent *L_dir = NULL;

    if (!dir)
        return 84;
    for (L_dir = readdir(dir); L_dir != NULL; L_dir = readdir(dir)) {
        if (L_dir->d_name[0] == '.')
            continue;
        if (access(L_dir->d_name, X_OK) == 0)
            bins[*index ++] = strdup(L_dir->d_name);
    }
    closedir(dir);
    return 0;
}

char **my_get_path(char *paths)
{
    char **path = my_str_split(paths, ":");
    char **bins = NULL;
    int len = 0;

    for (int i = 0; path[i]; i ++) {
        printf("looking into %s file\n", path[i]);
        len += count_file(strdup(path[i]));
    }
    bins = calloc(sizeof(char *), (len + 1));
    len = 0;
    if (bins == NULL)
        return NULL;
    for (int i = 0; path[i]; len ++)
        if (my_fill_bins(path[i], bins, &len) == 84)
            return NULL;
    return bins;
}
