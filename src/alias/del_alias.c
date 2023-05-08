/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** del_alias.c
*/

#include <stdbool.h>
#include <string.h>

#include "base.h"
#include "list.h"

#include "shell/alias.h"
#include "utils/cleanup.h"

static bool_t is_same(char *alias, char *input)
{
    AUTOFREE char **array = str_split(alias, " =");

    return !strcmp(array[2], input);
}

void del_alias(list_t *alias, char *input)
{
    LIST_FOREACH(alias, node) {
        if (is_same((char *)node->value, input)) {
            list_remove_node(alias, node);
            break;
        }
    }
}
