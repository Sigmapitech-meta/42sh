/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** add_alias.c
*/

#include "list.h"
#include "shell/alias.h"
#include "utils/sentinel.h"

int add_alias(list_t *alias, char *input)
{
    return (
        is_alias(input)
        && !IS_SENTINEL(list_append(alias, input))
    );
}
