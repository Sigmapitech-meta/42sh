/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** my_get_alias.c
*/

#include <stdlib.h>
#include <string.h>

#include "shell/auto_completion.h"
#include "shell/helpers.h"
#include "utils/cleanup.h"

static bool is_alias_1(char *str)
{
    if (strlen(str) < 5)
        return false;
    if (str[0] == 'a' &&
        str[1] == 'l' &&
        str[2] == 'i' &&
        str[3] == 'a' &&
        str[4] == 's')
        return true;
    return false;
}

static int count_alias(char **file_content)
{
    int count = 0;

    for (int i = 0; file_content[i]; i++)
        if (is_alias_1(file_content[i]))
            count++;
    return count;
}

static char **parse_alias(char **file)
{
    int line_nbr = count_alias(file);
    char **alias = calloc(sizeof(char *), (line_nbr + 1));
    int j = 0;

    if (!alias)
        return NULL;
    for (int i = 0; file[i]; i++)
        if (is_alias_1(file[i]) && strcmp(file[i], "") != 0)
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
    alias = my_str_split(file_content, "\n");
    alias = parse_alias(alias);
    return alias;
}
