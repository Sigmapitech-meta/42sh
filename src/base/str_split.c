/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** str_split.c
*/

#include <string.h>

#include "base.h"
#include "utils/cleanup.h"
#include "utils/sentinel.h"

int str_count_tok(char *string, char *delim)
{
    int i = 0;
    AUTOFREE char *copy = strdup(string);
    char *rest = NULL;

    if (!copy)
        return SENTINEL;
    if (!strtok_r(copy, delim, &rest))
        return 0;
    do {
        i++;
    } while (strtok_r(NULL, delim, &rest));
    return i;
}

static
char **str_split_populate(char *string, char **arr, char *delim)
{
    char *rest;
    char *token = strtok_r(string, delim, &rest);
    int i = 0;

    while (token) {
        arr[i++] = token;
        token = strtok_r(NULL, delim, &rest);
    }
    return arr;
}

char **str_nsplit(char *string, char *delim, int n)
{
    char **words = malloc(n * sizeof(char *));

    return NULL_OR(
        words, str_split_populate(string, words, delim)
    );
}

char **str_split(char *string, char *delim)
{
    size_t count = str_count_tok(string, delim);

    return NULL_OR(
        count, str_nsplit(string, delim, count)
    );
}
