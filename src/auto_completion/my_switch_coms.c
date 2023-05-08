/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** my_switch_coms.c
*/

#include <stddef.h>
#include <string.h>

#include "base.h"
#include "list.h"
#include "shell/auto_completion.h"
#include "shell/alias.h"

static
char *strdup_alias(char **array)
{
    char *output = strdup(array[4]);
    for (int i = 5; array[i]; i++)
        output = my_strcat(output, array[i]);
    return output;
}

static char *cmp_alias_and_input(char *node_value, char *input)
{
    char **array = str_split(node_value, " =");

    return (
        (!strcmp(array[2], input))
        ? strdup_alias(array) : NULL
    );
}

char *my_switch_coms(list_t *bins, char *input)
{
    char *output = NULL;

    LIST_FOREACH(bins, node) {
        if (is_alias(node->value))
            output = cmp_alias_and_input(node->value, input);
        if (output)
            return output;
        if (!strcmp(input, node->value))
            return node->value;
    }
    return NULL;
}
