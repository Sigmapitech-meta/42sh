/*
** EPITECH PROJECT, 2023
** my_print_recommandations.c
** File description:
** to print the recommandations
*/

#include "shell/auto_completion.h"

int my_print_recommendations(list_t *bins, char *input)
{
    int i = 0;

    for (list_node_t *node = bins->head; node; node = node->next) {
        if (start_the_same_way((char *)node->value, input)) {
            i += my_strlen((char *)node->value);
            print((char *)node->value);
            print(" ");
        }
        if (i >= 30)
            write(1, "\n", 1);
    }
    return 0;
}
