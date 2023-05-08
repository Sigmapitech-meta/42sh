/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** my_strcat.c
*/

#include <stdlib.h>
#include <string.h>

char *my_strcat(char *left, char *right)
{
    int len = strlen(left);
    int big_len = len + strlen(right);
    char *str = malloc((big_len + 1) * sizeof(char));

    strcpy(str, left);
    strcat(str + len, right);
    str[big_len] = '\0';
    return str;
}
