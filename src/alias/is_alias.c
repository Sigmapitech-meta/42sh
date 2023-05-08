/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** is_alias.c
*/

#include "shell/alias.h"
#include <stdbool.h>
#include <string.h>
#include "utils/cleanup.h"

bool is_alias(char *str)
{
    AUTOFREE char **words = my_str_split(str, " =");

    if (!words[1] || !words[2])
        return false;
    if (strcmp(words[0], "alias") != 0)
        return false;
    return true;
}
