/*
** EPITECH PROJECT, 2023
** Kepler
** File description:
** mock_stat.c
*/

#include <unistd.h>
#include <bits/types/FILE.h>
#include <string.h>

#include "epitech.h"
#include "mocks/mock_getline.h"

bool_t *getline_activation_ptr(void)
{
    static bool_t enabled = FALSE;

    return &enabled;
}

ssize_t wrap_getline(char **line, size_t *read, file_t *stream)
{
    static int index = 0;

    if (!GETLINE_TOGGLE)
        return real_getline(line, read, stream);
    *line = strdup(GETlINE_TABLE[index++ % GETLINE_TABLE_LENGTH]);
    return (ssize_t)strlen(*line);
}

void use_mock_getline(void)
{
    GETLINE_TOGGLE = TRUE;
}

void use_normal_getline(void)
{
    GETLINE_TOGGLE = FALSE;
}
