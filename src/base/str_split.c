/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** str_split.c
*/

#include <string.h>
#include "utils/autofree.h"
#include "utils/sentinel.h"
#include "epitech.h"

int str_count(char *string, char *delim)
{
    int i = 0;
    AUTOFREE char *copy = strdup(string);
    char *token;
    char *rest;

    if (!copy)
        return W_SENTINEL;
    token = strtok_r(copy, delim, &rest);
    if (!token)
        return 0;
    while (token) {
        token = strtok_r(NULL, delim, &rest);
        i++;
    }
    return i;
}

static
bool_t str_split_populate(char *string, char **arr, char *delim)
{
    char *rest;
    char *token = strtok_r(string, "\n", &rest);
    int i = 0;

    while (token) {
        arr[i++] = token;
        if (strchr(token, ' '))
            return FALSE;
        token = strtok_r(NULL, delim, &rest);
    }
    return TRUE;
}

char **str_split(char *string, char *delim)
{
    bool_t succeed;
    size_t count = str_count(string, delim);
    char **words;

    if (!count)
        return NULL;
    words = malloc(count * sizeof(char *));
    if (!words)
        return NULL;
    succeed = str_split_populate(string, words, delim);
    if (!succeed) {
        free(words);
        return NULL;
    }
    return words;
}
