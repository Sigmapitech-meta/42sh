/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** get_line.c
*/

#include <stddef.h>
#include <stdio.h>

#include "base.h"

file_t **source_location(void)
{
    static file_t *file = NULL;

    if (!file)
        file = stdin;
    return &file;
}

void set_getline_source(file_t *file)
{
    GET_SOURCE_LOCATION = file;
}

size_t get_line(char **line)
{
    static size_t zero = 0;

    return getline(line, &zero, GET_SOURCE_LOCATION);
}
