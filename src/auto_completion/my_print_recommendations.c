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

static int my_print_com(char *com)
{
    int len = strlen(com);
    printf("%s\t", com);
    len += 4;
    return len;
}

char *my_print_recommendations(list_t *bins, char *input)
{
    int i = 0;
    int count = 0;
    int save = 0;

    LIST_FOREACH(bins, node) {
        save = i;
        if (start_the_same_way((char *)node->value, input))
            i += my_print_com((char *)node->value);
        if (i >= 30) {
            i = 0;
            printf("\n");
        }
        if (save != i)
            count ++;
    }
    printf("\n");
    if (count == 1)
        input = my_switch_coms(bins, input);
    return input;
}
