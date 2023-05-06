/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** list_get.c
*/

#include <stddef.h>

#include "base.h"
#include "list.h"

list_node_t *list_get_node(list_t *list, uint_t index)
{
    list_node_t *node = NULL_OR(list, list->head);
    uint_t curr = 0;

    while (node && curr < index) {
        node = node->next;
        curr++;
    }
    return node;
}

void *list_get(list_t *list, uint_t index)
{
    list_node_t *node = list_get_node(list, index);

    return NULL_OR(node, node->value);
}
