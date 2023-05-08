/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** my_print_recommendations.c
*/

#include <stdio.h>
#include <string.h>

#include "list.h"
#include "shell/auto_completion.h"

static
bool_t start_the_same_way(char *bin, char *input)
{
    return !strncmp(bin, input, strlen(bin));
}

static
int my_print_com(char *com)
{
    printf("%s\t", com);
    return strlen(com) + 4;
}

char *my_print_recommendations(list_t *bins, char *input)
{
    int i = 0;
    int count = 0;
    int save;

    LIST_FOREACH(bins, node) {
        save = i;
        if (start_the_same_way(node->value, input))
            i += my_print_com(node->value);
        if (i >= 30) {
            i = 0;
            printf("\n");
        }
        if (save != i)
            count++;
    }
    printf("\n");
    return (
        (count != 1) ?
        input : my_switch_coms(bins, input)
    );
}
