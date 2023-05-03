/*
** EPITECH PROJECT, 2023
** Kepler
** File description:
** mock_stat.c
*/

#include <unistd.h>
#include <bits/types/FILE.h>
#include <string.h>

#include "mocks/mock_getline.h"
#include "utils/sentinel.h"

gl_mock_t *getline_mock_ptr(void)
{
    static gl_mock_t data = { .mode = NORMAL, 0};

    return &data;
}

ssize_t wrap_getline(char **line, size_t *read, file_t *stream)
{
    static int index = 0;
    char *read_line;

    if (GETLINE_DATA->mode == BROKEN) {
        *line = NULL;
        return W_SENTINEL;
    }
    if (GETLINE_DATA->mode == TABLE) {
        read_line = GETLINE_DATA->table[index++];
        if (!read_line) {
            *line = read_line;
            return (ssize_t) strlen(*line);
        } else {
            *line = NULL;
            return W_SENTINEL;
        }
    }
    return real_getline(line, read, stream);
}
