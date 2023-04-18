/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** put a char
*/

#include <unistd.h>
#include "epitech/printf.h"

int w_putstr(int fd, char *str)
{
    int i = 0;

    for (; str[i]; i++)
        w_putchar(fd, str[i]);
    return i;
}

int w_putchar(int fd, char c)
{
    return (int)write(fd, &c, 1);
}
