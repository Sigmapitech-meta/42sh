/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** list_append.c
*/

#include <malloc.h>

#include "list.h"
#include "wololo/utils.h"

uint_t list_append_node(list_t *list, list_node_t *node)
{
    list->size++;
    if (!list->tail) {
        list->tail = node;
        list->head = node;
        return 0;
    }
    list->tail->next = node;
    node->prev = list->tail;
    list->tail = node;
    return list->size - 1;
}

uint_t list_append(list_t *list, void *value)
{
    list_node_t *node;

    if (!value)
        return W_SENTINEL;
    node = malloc(sizeof(list_node_t));
    if (!node)
        return W_SENTINEL;
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return list_append_node(list, node);
}
