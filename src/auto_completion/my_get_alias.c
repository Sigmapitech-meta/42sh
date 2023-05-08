/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** my_get_alias.c
*/

#include <stdlib.h>
#include <string.h>

#include "base.h"
#include "epitech.h"

#include "shell/auto_completion.h"
#include "utils/cleanup.h"

static
bool_t is_alias_1(char *str)
{
    return !strncmp(str, "alias", 5);
}

static
int count_alias(char **file_content)
{
    int count = 0;

    for (int i = 0; file_content[i]; i++)
        if (is_alias_1(file_content[i]))
            count++;
    return count;
}

static
char **parse_alias(char **file)
{
    int line_nbr = count_alias(file);
    char **alias = malloc((line_nbr + 1) * sizeof(char *));
    int j = 0;

    if (!alias)
        return NULL;
    for (int i = 0; file[i]; i++)
        if (file[i] && is_alias_1(file[i]))
            alias[j++] = strdup(file[i]);
    alias[line_nbr] = NULL;
    return alias;
}

char **my_get_alias(void)
{
    char **alias = NULL;
    AUTOFREE char *file_content = file_read(".42shrc");

    if (!file_content)
        return NULL;
    alias = str_split(file_content, "\n");
    return parse_alias(alias);
}
