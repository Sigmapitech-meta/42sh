/*
** EPITECH PROJECT, 2023
** alias_com.c
** File description:
** to reproduce the behavior of the alias command
*/

#include "shell/alias.h"

void alias_command(list_t *alias)
{
    list_node_t *node = alias->head;

    while (node != NULL) {
        if (is_alias((char *)node->value))
            printf("%s\n", (char *)node->value);
        node = node->next;
    }
    return;
}
