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
#include "shell/shell.h"

static
char *alias_replace_string(char *alias)
{
    AUTOFREE char **line = str_split(alias, " =");

    return NULL_OR(
        (line && line[0] && line[1]),
        strdup(alias + strlen(line[0]) + strlen(line[1]))
    );
}

bool_t is_alias(char *str)
{
    AUTOFREE char **words = str_split(str, " =");

    return (
        words && words[1] && words[2]
        && !strcmp(words[0], "alias")
    );
}

bool_t alias_is_same_key(char *alias, char *input)
{
    AUTOFREE char **array = str_split(alias, " =");

    return !strcmp(array[1], input);
}

void alias_print_command(aliases_t *aliases)
{
    list_t *pool;

    if (!aliases)
        return;
    pool = aliases->pool;
    if (!pool)
        return;
    if (!pool->size) {
        printf("No aliases found.\n");
        return;
    }
    LIST_FOREACH(aliases->pool, node)
        printf("%s\n", (char *)node->value);
}

char *alias_resolve(aliases_t *aliases, char *input)
{
    if (!aliases)
        return input;
    LIST_FOREACH(aliases->pool, node)
        if (alias_is_same_key(node->value, input))
            return alias_replace_string(node->value);
    return input;
}
