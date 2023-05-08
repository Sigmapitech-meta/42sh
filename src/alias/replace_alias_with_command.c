/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** replace_alias_with_command.c
*/

#include "shell/alias.h"

static bool is_similar(char *alias_given, char *input)
{
    AUTOFREE char **alias = my_str_split(alias_given, " =");

    if (strcmp(alias[2], input) == 0)
        return true;
    return false;
}

static char *get_command(char *alias)
{
    AUTOFREE char **line = my_str_split(alias, " =");
    char *com = NULL;
    int i = 0;

    while (line[i] != NULL && strcmp(line[i], "=") != 0)
        i++;
    i++;
    while (line[i] != NULL)
        com = my_strcat(com, line[i++]);
    return com;
}

char *replace_alias_with_command(list_t *alias, char *input)
{
    list_node_t *node = alias->head;
    char **array = NULL;

    while (node != NULL && !is_similar((char *)node->value, input))
        node = node->next;
    if (node == NULL)
        return input;
    array = my_str_split((char *)node->value, " =");
    input = get_command((char *)node->value);
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
    return input;
}
