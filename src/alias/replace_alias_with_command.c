/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** replace_alias_with_command.c
*/

#include <string.h>

#include "base.h"
#include "list.h"

#include "shell/alias.h"
#include "utils/cleanup.h"

static
char *get_command(char *alias)
{
    AUTOFREE char **line = str_split(alias, " =");

    return NULL_OR(
        (line && line[0] && line[1]),
        strdup(alias + strlen(line[0]) + strlen(line[1]))
    );
}

char *replace_alias_with_command(list_t *alias, char *input)
{
    LIST_FOREACH(alias, node)
        if (is_the_same_alias(node->value, input))
            return get_command(node->value);
    return input;
}
