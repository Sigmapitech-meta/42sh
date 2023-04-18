/*
** EPITECH PROJECT, 2023
** Minishell
** File description:
** Interpreter
*/

#include <string.h>
#include <stdlib.h>

#include "epitech/base.h"

int param_count(const char *line)
{
    int count = 0;
    char *checkpoint;
    char *line_copy = str_duplicate((char *)line);
    char *token = strtok_r(line_copy, " \t", &checkpoint);

    if (!token)
        return 0;
    count++;
    while (strtok_r(NULL, " \t", &checkpoint))
        count++;
    free(line_copy);
    return count;
}

void param_fill(char **params, char *string)
{
    int i = 0;
    char *token;
    char *checkpoint;

    token = strtok_r(string, " \t", &checkpoint);
    while (token) {
        params[i] = token;
        token = strtok_r(NULL, " \t", &checkpoint);
        i++;
    }
}
