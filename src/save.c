/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** open_save.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
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
    AUTOCLOSE_FILE FILE *fd = fopen(".42sh_history" , "w+");
    char *line;

    if (!fd)
        return TRUE;
    LIST_FOREACH(list, buffer) {
        if (strstr((char *)buffer->value, "\n")) {
            line = (char *)buffer->value;
            line[strlen((char *)buffer->value) - 1] = '\0';
        }
        if (IS_SENTINEL(fprintf(fd, "%s\n", (char *)buffer->value)))
            return TRUE;
        }
    return FALSE;
}

static
int save_open(list_t *list)
{
    AUTOCLOSE_FILE FILE *fd = fopen(".42sh_history", "r");
    AUTOFREE char *line = NULL;

    if (!fd)
        return SENTINEL;
    while (!IS_SENTINEL_OF(get_saved_line(&line, fd), size_t))
        list_append(list, strdup(line));
    return EXIT_OK;
}

int shell_save_history(list_t *list)
{
    if (!list)
        return SENTINEL;
    return save_open(list) | save_to_file(list);
}
