/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** add_alias.c
*/

#include <stddef.h>
#include <stdlib.h>

#include "list.h"
#include "shell/alias.h"

int add_alias(list_t *alias, char *input)
{
    list_node_t *node = alias->head;
    list_node_t *new_node = calloc(sizeof(list_node_t), 1);

    if (!is_alias(input))
        return 84;
    while (node != NULL)
        node = node->next;
    new_node->value = input;
    list_append_node(alias, new_node);
    return 0;
}
