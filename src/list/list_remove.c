/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** list_remove.c
*/

#include <malloc.h>
#include "list.h"

void list_remove_node(list_t *list, list_node_t *node)
{
    list->size--;
    if (list->head == node)
        list->head = node->next;
    if (list->tail == node)
        list->tail = node->prev;
    if (node->prev)
        node->prev->next = node->next;
    if (node->next)
        node->next->prev = node->prev;
    node->next = NULL;
    node->prev = NULL;
    free(node);
}

void list_remove(list_t *list, uint_t index)
{
    list_node_t *node;

    if (!list)
        return;
    node = list_get_node(list, index);
    if (node)
        list_remove_node(list, node);
}
