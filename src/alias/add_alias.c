/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** add_alias.c
*/

#include "shell/alias.h"
#include <stdlib.h>
#include <stddef.h>

int add_alias(list_t *alias, char *input)
{
    list_node_t *node = alias->head;
    list_node_t *newnode = calloc(sizeof(list_node_t), 1);

    if (!is_alias(input))
        return 84;
    while (node != NULL)
        node = node->next;
    newnode->value = input;
    list_append_node(alias, newnode);
    return 0;
}
