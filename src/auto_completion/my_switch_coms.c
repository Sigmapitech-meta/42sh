/*
** EPITECH PROJECT, 2023
** my_switch_coms.c
** File description:
** to switch the command with the only one corresponding
*/

#include "shell/auto_completion.h"

char *my_switch_coms(list_t *bins, char *input)
{
    list_node_t *node = bins->head;
    char *output = NULL;

    while (node != NULL) {
        if (output != NULL)
            return output;
        if (strcmp(input, (char *)node->value) == 0)
            return (char *)node->value;
        node = node->next;
    }
    return NULL;
}
