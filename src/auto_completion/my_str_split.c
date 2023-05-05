/*
** EPITECH PROJECT, 2023
** my_str_split_2.c
** File description:
** alternative version of str_split
*/

#include "shell/auto_completion.h"

static bool check_char(char c, char *seps)
{
    for (int i = 0; seps[i]; i ++)
        if (seps[i] == c)
            return true;
    return false;
}

static int my_getnbr_ptr(char *str, char *seps)
{
    int nb = 0;
    int len = strlen(str);

    for (int i = 0; str[i]; i ++)
        if (check_char(str[i], seps) && !check_char(str[i - 1], seps))
            nb += 2;
    if (!check_char(str[len - 1], seps))
        nb ++;
    return nb;
}

static int my_get_count(char *str, int count, char *seps)
{
    while (str[count] && !check_char(str[count], seps))
        count ++;
    return count;
}

static int my_get_char_count(char *str, int count, char *seps)
{
    while (str[count] && check_char(str[count], seps))
        count ++;
    return count;
}

char **my_str_split(char *str, char *seps)
{
    int nb = my_getnbr_ptr(str, seps);
    char **array = calloc(sizeof(char *), nb + 2);
    int tmp = 0;
    int index = 0;
    int count = 0;
    int oldcount = 0;

    for (int i = 0; i != nb; i ++, tmp = 0) {
        if (str[count] && !check_char(str[count], seps))
            count = my_get_count(str, count, seps);
        else
            count = my_get_char_count(str, count, seps);
        array[i] = calloc(sizeof(char), (count - oldcount) + 1);
        for (int j = oldcount; j != count; j ++)
            array[index][tmp ++] = str[j];
        array[index ++][tmp] = '\0';
        oldcount += (count - oldcount);
    }
    array[nb + 1] = NULL;
    return array;
}
