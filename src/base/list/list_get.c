/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** list_get.c
*/

#include <stddef.h>

#include "epitech/list.h"

list_node_t *list_get_node(list_t *list, uint_t index)
{
    list_node_t *node;
    uint_t curr = 0;

    if (!list)
        return NULL;
    node = list->head;
    if (!node)
        return NULL;
    while (node && curr < index) {
        node = node->next;
        curr++;
    }
    return node;
}

void *list_get(list_t *list, uint_t index)
{
    list_node_t *node = list_get_node(list, index);

    if (!node)
        return NULL;
    return node->value;
}
