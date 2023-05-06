/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** my_strcat.c
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int my_stringlen(char const *str)
{
    int nb = 0;

    if (str == NULL)
        return nb;
    while (str[nb])
        nb++;
    return nb;
}

char *my_strcat(char *src1, char *src2)
{
    int i = 0;
    int len = my_stringlen(src1);
    int biglen = len + my_stringlen(src2);
    char *str = calloc(sizeof(char), biglen + 1);

    while (i < len) {
        str[i] = src1[i];
        i++;
    }
    while (i < biglen) {
        str[i] = src2[i - len];
        i++;
    }
    str[biglen] = '\0';
    return str;
}
