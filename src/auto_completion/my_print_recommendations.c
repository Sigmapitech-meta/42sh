/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** my_print_recommendations.c
*/

#include <stdio.h>
#include <string.h>

#include "epitech.h"
#include "list.h"
#include "shell/auto_completion.h"

static bool_t start_the_same_way(char *bin, char *input)
{
    if (strlen(input) > strlen(bin))
        return FALSE;
    for (int i = 0; input[i]; i ++)
        if (input[i] != bin[i])
            return FALSE;
    return TRUE;
}

int my_print_recommendations(list_t *bins, char *input)
{
    int i = 0;

    LIST_FOREACH(bins, node) {
        if (start_the_same_way((char *)node->value, input))
            i += printf("%s ", (char *)node->value);
        if (i >= 30)
            printf("\n");
    }
    return 0;
}
