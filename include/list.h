/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** list.h
*/

#ifndef LIST_H_
    #define LIST_H_

    #include "coding_style_fix.h"
    #include "utils/attributes.h"

    #include <stdlib.h>

    #define LIST_FOREACH(l, n) for (list_node_t *n EQ l->head; n; n EQ n->next)
    #define LIST_APPEND_CHECK(l, v) (list_append(l, v) != W_SENTINEL)

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

/**
 * @brief append a value to the list
 *
 * @param list the list
 * @param value the value
 * @return ssize_t : the size of the list
 */
ssize_t list_append(list_t *list, void *value);
/**
 * @brief append a node to the list
 *
 * @param list the list
 * @param node the node
 * @return ssize_t : the size of the list
 */
ssize_t list_append_node(list_t *list, list_node_t *node);

/**
 * @brief get a value from the list
 *
 * @param list the list
 * @param index the index
 * @return void* : the value
 */
void *list_get(list_t *list, uint_t index);
/**
 * @brief get a node from the list
 *
 * @param list the list
 * @param index the index
 * @return list_node_t* : the node
 */
list_node_t *list_get_node(list_t *list, uint_t index);

/**
 * @brief remove a value from the list
 *
 * @param list the list
 * @param index the index
 */
void list_remove(list_t *list, uint_t index);
/**
 * @brief remove a node from the list
 *
 * @param list the list
 * @param node the node
 */
void list_remove_node(list_t *list, list_node_t *node);
/**
 * @brief clear the list
 *
 * @param list the list
 */
void list_clear(list_t *list);

/**
 * @brief create a list
 *
 * @return USED* : the list
 */
static inline
USED list_t *list_create(void)
{
    return calloc(1, sizeof(list_t));
}

static inline
USED void list_destroy(list_t *list)
{
    list_clear(list);
    free(list);
}

#endif /* !LIST_H_ */
