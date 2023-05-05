/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** list_management.c
*/

#include <stdlib.h>
#include "list.h"

list_t *list_create(void)
{
    list_t *list = malloc(sizeof(list_t));

    if (!list)
        return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void list_destroy(list_t *list)
{
    list_clear(list);
    free(list);
}
