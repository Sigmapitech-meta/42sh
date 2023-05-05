/*
** EPITECH PROJECT, 2023
** is_alias.c
** File description:
** to check wether or not the string passed is an alias
*/

#include "shell/alias.h"
#include <stdbool.h>
#include <string.h>
#include "utils/autofree.h"

bool is_alias(char *str)
{
    AUTOFREE char **words = my_str_split(str, " =");

    if (!words[1] || !words[2])
        return false;
    if (strcmp(words[0], "alias") != 0)
        return false;
    return true;
}
