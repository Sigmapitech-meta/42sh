/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** list_append.c
*/

#include <stdlib.h>

#include "base.h"
#include "list.h"
#include "utils/sentinel.h"

ssize_t list_append_node(list_t *list, list_node_t *node)
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

ssize_t list_append(list_t *list, void *value)
{
    list_node_t *node;

    if (!value)
        return SENTINEL;
    node = malloc(sizeof(list_node_t));
    if (!node)
        return SENTINEL;
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return list_append_node(list, node);
}

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
