/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias_mgmt.c
*/

#include "list.h"

#include "shell/alias.h"
#include "utils/sentinel.h"

int alias_add(list_t *alias, char *input)
{
    return (
        is_alias(input)
        && !IS_SENTINEL(list_append(alias, input))
    );
}

void alias_remove(list_t *alias, char *input)
{
    LIST_FOREACH(alias, node) {
        if (alias_is_same_key(node->value, input)) {
            list_remove_node(alias, node);
            break;
        }
    }
}
