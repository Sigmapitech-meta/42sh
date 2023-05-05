/*
** EPITECH PROJECT, 2023
** create_alias_list.c
** File description:
** to create the list of alias
*/

#include "shell/alias.h"

list_t *create_list_alias(void)
{
    list_t *list = list_create();
    AUTOFREE char *file_content = file_read(".42shrc");
    AUTOFREE char **lines = NULL;

    if (!file_content)
        return NULL;
    lines = my_str_split(file_content, "\n");
    for (int i = 0; lines[i]; i ++)
        if (is_alias(lines[i]))
            list_append(list, lines[i]);
    return list;
}
