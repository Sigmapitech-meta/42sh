/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** list_destroy.c
*/
#include "epitech/list.h"

void list_destroy(list_t *list)
{
    while (list->size)
        list_remove_node(list, list->tail);
}
