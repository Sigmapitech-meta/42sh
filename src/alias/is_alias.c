/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** is_alias.c
*/

#include <string.h>

#include "shell/alias.h"
#include "utils/cleanup.h"
#include "base.h"

bool_t is_alias(char *str)
{
    AUTOFREE char **words = str_split(str, " =");

    return (
        words && words[1] && words[2]
        && !strcmp(words[0], "alias")
    );
}
