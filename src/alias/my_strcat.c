/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** my_strcat.c
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int my_stringlen(char const *str)
{
    int nb = 0;

    if (!str)
        return nb;
    while (str[nb])
        nb++;
    return nb;
}

char *my_strcat(char *src1, char *src2)
{
    int i = 0;
    int len = my_stringlen(src1);
    int big_len = len + my_stringlen(src2);
    char *str = calloc(sizeof(char), big_len + 1);

    while (i < len) {
        str[i] = src1[i];
        i++;
    }
    while (i < big_len) {
        str[i] = src2[i - len];
        i++;
    }
    str[big_len] = '\0';
    return str;
}
