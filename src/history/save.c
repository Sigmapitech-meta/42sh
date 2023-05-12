/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** save.c
*/

#include <stdio.h>
#include <string.h>

#include "list.h"
#include "utils/sentinel.h"
#include "utils/cleanup.h"

ssize_t get_saved_line(char **line, FILE *fd)
{
    static size_t zero = 0;

    return getline(line, &zero, fd);
}

list_t *save_open(void)
{
    AUTO_FCLOSE FILE *fd = fopen(".42sh_history", "r");
    AUTO_FREE char *line = NULL;
    list_t *list = list_create();
    char *tmp;

    if (!list)
        return NULL;
    if (!fd)
        return list;
    while (!IS_SENTINEL_OF(get_saved_line(&line, fd), ssize_t)) {
        tmp = strstr(line, "\n");
        if (tmp)
            line[tmp - line] = '\0';
        if (IS_SENTINEL_OF(list_append(list, strdup(line)), ssize_t))
            return list;
    }
    return list;
}