/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** is_alias.c
*/

#include <string.h>

#include "epitech.h"
#include "shell/alias.h"
#include "utils/cleanup.h"

bool_t is_alias(char *str)
{
    AUTOFREE char **words = my_str_split(str, " =");

    if (!words[1] || !words[2])
        return FALSE;
    if (strcmp(words[0], "alias") != 0)
        return FALSE;
    return TRUE;
}
