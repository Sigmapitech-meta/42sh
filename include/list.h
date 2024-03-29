/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** list.h
*/

#ifndef LIST_H_
    #define LIST_H_

/**
 * @file list.h
 * @author Gabriel Hosquet (gabriel.hosquet@epitech.eu)
 * @author Yohann Boniface(edhyjox@gmail.com)
 * @brief List
 * @version 0.1
 *
 */

    #include "base.h"
    #include "coding_style_fix.h"
    #include "utils/attributes.h"
    #include "utils/debug_mode.h"

    #include <stdio.h>
    #include <stdlib.h>

    #define LIST_FOREACH(l, n) for (list_node_t *n EQ l->head; n; n EQ n->next)

typedef unsigned int uint_t;
typedef long ssize_t;

typedef struct list_s list_t;
typedef struct list_node_s list_node_t;

struct list_node_s {
    void *value;
    list_node_t *next;
    list_node_t *prev;
};

struct list_s {
    list_node_t *head;
    list_node_t *tail;
    ssize_t size;
};

/** @brief append a value to the list */
ssize_t list_append(list_t *list, void *value);

/** @brief append a node to the list */
ssize_t list_append_node(list_t *list, list_node_t *node);

/** @brief get a node from the list */
list_node_t *list_get_node(list_t *list, uint_t index);

/** @brief remove a value from the list */
void list_remove(list_t *list, uint_t index);

/** @brief remove a node from the list */
void list_remove_node(list_t *list, list_node_t *node);

/** @brief create a list */
static inline
USED list_t *list_create(void)
{
    return calloc(1, sizeof(list_t));
}

/** @brief get index from a node */
static inline
USED int list_get_index(list_t *list, list_node_t *node)
{
    int i = 0;

    LIST_FOREACH(list, n) {
        if (n == node)
            return i;
        i++;
    }
    return SENTINEL;
}

/** @brief get an element from a list */
static inline
USED void *list_get(list_t *list, uint_t index)
{
    list_node_t *node = list_get_node(list, index);

    return NULL_OR(node, node->value);
}

/** @brief clear the list */
static inline
USED void list_clear(list_t *list)
{
    while (list->size)
        list_remove_node(list, list->tail);
}

/** @brief destroy a list */
static inline
USED void list_destroy(list_t *list)
{
    list_clear(list);
    free(list);
}

#endif /* !LIST_H_ */
