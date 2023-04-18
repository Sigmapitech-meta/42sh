/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** str_dup.c
*/
#include <stdlib.h>

#include "epitech/base.h"
#include "wololo/debug_mode.h"

char *str_duplicate(char *src)
{
    int len = str_len(src);
    char *out = malloc((len + 1) * sizeof(char));

    if (!out)
        return NULL;
    str_copy(src, out);
    return out;
}
