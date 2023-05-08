/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias_command.c
*/

#include <stdio.h>
#include "shell/alias.h"
#include "list.h"

void alias_command(list_t *alias)
{
    list_node_t *node = alias->head;

    while (node != NULL) {
        if (is_alias((char *)node->value))
            printf("%s\n", (char *)node->value);
        node = node->next;
    }
}
