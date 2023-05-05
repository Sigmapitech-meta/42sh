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
    return calloc(1, sizeof(list_t));
}

void list_destroy(list_t *list)
{
    list_clear(list);
    free(list);
}
