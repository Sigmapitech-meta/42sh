/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias_command.c
*/

#include <stdio.h>
#include "shell/alias.h"
#include "list.h"

void alias_command(list_t *alias)
{
    LIST_FOREACH(alias, node)
        if (is_alias(node->value))
            printf("%s\n", (char *)node->value);
}
