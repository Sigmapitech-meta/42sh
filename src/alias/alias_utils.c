/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias_utils.c
*/

#include <stdio.h>
#include <string.h>

#include "base.h"

#include "list.h"
#include "shell/alias.h"
#include "utils/cleanup.h"

static
char *alias_replace_string(char *alias)
{
    AUTOFREE char **line = str_split(alias, " =");

    return NULL_OR(
        (line && line[0] && line[1]),
        strdup(alias + strlen(line[0]) + strlen(line[1]))
    );
}

bool_t alias_is_same_key(char *alias, char *input)
{
    AUTOFREE char **array = str_split(alias, " =");

    return !strcmp(array[1], input);
}

void alias_print_command(list_t *alias)
{
    LIST_FOREACH(alias, node)
        printf("%s\n", (char *)node->value);
}

char *alias_resolve(list_t *alias, char *input)
{
    LIST_FOREACH(alias, node)
        if (alias_is_same_key(node->value, input))
            return alias_replace_string(node->value);
    return input;
}
