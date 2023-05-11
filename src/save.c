/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** save.c
*/

#include <stdio.h>
#include <string.h>

#include "list.h"
#include "epitech.h"
#include "utils/sentinel.h"
#include "utils/cleanup.h"

size_t get_saved_line(char **line, FILE *fd)
{
    static size_t zero = 0;

    return getline(line, &zero, fd);
}

static
bool_t save_to_file(list_t *list)
{
    AUTO_FCLOSE FILE *fd = fopen(".42sh_history" , "w+");
    char *line;

    if (!fd)
        return TRUE;
    LIST_FOREACH(list, buffer) {
        if (strstr(buffer->value, "\n")) {
            line = (char *)buffer->value;
            line[strlen(line) - 1] = '\0';
        }
        if (IS_SENTINEL(fprintf(fd, "%s\n", (char *)buffer->value)))
            return TRUE;
    }
    return FALSE;
}

static
int save_open(list_t *list)
{
    AUTO_FCLOSE FILE *fd = fopen(".42sh_history", "r");
    AUTO_FREE char *line = NULL;

    if (!fd)
        return SENTINEL;
    while (
        !IS_SENTINEL_OF(get_saved_line(&line, fd), size_t)
        && !IS_SENTINEL_OF(list_append(list, strdup(line)), ssize_t)
    );
    return EXIT_OK;
}

int shell_save_history(list_t *list)
{
    if (!list)
        return SENTINEL;
    return save_open(list) | save_to_file(list);
}
