/*
** EPITECH PROJECT, 2023
** print_coms.c
** File description:
** print_commands_list
*/

#include "shell/auto_completion.h"

void print_coms(list_t *bins)
{
    list_node_t *node = bins->head;

    while (node != NULL && !is_alias((char *)node->value)) {
        printf("%s\n", (char *)node->value);
        node = node->next;
    }
    alias_command(bins);
    return;
}
