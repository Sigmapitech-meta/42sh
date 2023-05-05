/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** my_switch_coms.c
*/

#include "shell/auto_completion.h"

static char *strdup_alias(char **array)
{
    char *output = NULL;
    int len = 0;

    for (int i = 4; array[i] != NULL; i ++)
        len += strlen(array[i]);
    output = calloc(1, (len + 1));
    output = strdup(array[4]);
    for (int i = 5; array[i] != NULL; i ++)
        output = my_strcat(output, array[i]);
    return output;
}

static char *cmp_alias_and_input(char *node_value, char *input)
{
    char *output = NULL;
    char **array = my_str_split(node_value, " =");

    if (strcmp(array[2], input) == 0)
        output = strdup_alias(array);
    return output;
}

char *my_switch_coms(list_t *bins, char *input)
{
    list_node_t *node = bins->head;
    char *output = NULL;

    while (node != NULL) {
        if (is_alias((char *)node->value))
            output = cmp_alias_and_input((char *)node->value, input);
        if (output != NULL)
            return output;
        if (strcmp(input, (char *)node->value) == 0)
            return (char *)node->value;
        node = node->next;
    }
    return NULL;
}
