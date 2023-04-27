/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** list_create.c
*/

#include <malloc.h>
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
