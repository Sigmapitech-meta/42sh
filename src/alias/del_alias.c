/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** del_alias.c
*/

#include <stdbool.h>
#include <string.h>

#include "list.h"
#include "shell/alias.h"
#include "utils/cleanup.h"

static bool is_same(char *alias, char *input)
{
    AUTOFREE char **array = my_str_split(alias, " =");

    if (strcmp(array[2], input) == 0)
        return true;
    return false;
}

void del_alias(list_t *alias, char *input)
{
    list_node_t *node = alias->head;
    uint_t index = 0;

    while (node != NULL && !is_same((char *)node->value, input)) {
        node = node->next;
        index++;
    }
    if (node == NULL)
        return;
    list_remove(alias, index);
    return;
}
