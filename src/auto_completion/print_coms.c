/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** print_coms.c
*/

#include <stdio.h>

#include "list.h"
#include "shell/auto_completion.h"
#include "shell/alias.h"

void print_coms(list_t *bins)
{
    list_node_t *node = bins->head;

    while (node && !is_alias(node->value)) {
        printf("%s\n", (char *)node->value);
        node = node->next;
    }
    alias_command(bins);
}

