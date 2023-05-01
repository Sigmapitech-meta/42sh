/*
** EPITECH PROJECT, 2023
** my_str_split.c
** File description:
** the ultimate version of the str to word array
*/

#include "shell/auto_completion.h"
#include <stdbool.h>
#include <stdlib.h>

static bool check_char(char c, char *seps)
{
    if (seps == NULL)
        seps = "\n";
    for (int j = 0; seps[j]; j ++)
        if (c == seps[j])
            return true;
    return false;
}

static int my_get_nbr_ptr(char *str, char *seps)
{
    int nb = 0;

    for (int i = 0; str[i]; i ++)
        if (check_char(str[i], seps))
            nb ++;
    return nb;
}

int my_fill_ptr(char *dest, char *src, int oldcount, int count)
{
    int i = 0;

    for (int j = oldcount; j != (count + oldcount); j ++)
        dest[i ++] = src[j];
    dest[i] = '\0';
    return 0;
}

char **my_str_split(char *str, char *seps)
{
    int nb = my_get_nbr_ptr(str, seps);
    char **array = calloc(sizeof(char *), nb + 2);
    int count = 0;
    int oldcount = 0;
    int index = 0;

    for (int i = 0; index != nb + 1; i ++, index ++) {
        count = 0;
        while (str[i] && !check_char(str[i], seps)) {
            count ++;
            i ++;
        }
        array[index] = calloc(sizeof(char), count + 1);
        if (oldcount != 0)
            oldcount ++;
        my_fill_ptr(array[index], str, oldcount, count);
        oldcount += count;
    }
    array[nb + 1] = NULL;
    return array;
}
