/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** my_get_alias.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "epitech.h"
#include "shell/auto_completion.h"
#include "shell/helpers.h"
#include "utils/autofree.h"

static
bool_t is_alias(char *str)
{
    return strcmp(str, "alias");
}

static int count_alias(char **file_content)
{
    int count = 0;

    for (int i = 0; file_content[i]; i++)
        if (is_alias(file_content[i]))
            count++;
    return count;
}

static char **parse_alias(char **file)
{
    int line_nbr = count_alias(file);
    char **alias = calloc(sizeof(char *), (line_nbr + 1));
    char **one_alias = NULL;
    int j = 0;

    if (!alias)
        return NULL;
    for (int i = 0; file[i]; i ++)
        if (is_alias(file[i]) && strcmp(file[i], "") != 0) {
            one_alias = my_str_split(file[i], " =");
            alias[j++] = strdup(one_alias[1]);
        }
    alias[line_nbr] = NULL;
    return alias;
}

char **my_get_alias(void)
{
    char **alias = NULL;
    AUTOFREE char *file_content = file_read(".42shrc");

    if (!file_content)
        return NULL;
    alias = my_str_split(file_content, "\n");
    alias = parse_alias(alias);
    return alias;
}
