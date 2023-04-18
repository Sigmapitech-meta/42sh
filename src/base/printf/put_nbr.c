/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** put a number
*/
#include "epitech/printf.h"

int my_putpos(int fd, unsigned int nb)
{
    if (nb > 9) {
        my_putpos(fd, nb / 10);
    }
    w_putchar(fd, (char)('0' | (nb % 10)));
    return 0;
}

int put_nbr(int fd, int nb)
{
    int abs_n;

    if (nb < 0) {
        w_putchar(fd, '-');
        abs_n = -nb;
    } else {
        abs_n = nb;
    }
    if (abs_n < 0) {
        abs_n = -(nb / 10);
        my_putpos(fd, abs_n);
        w_putchar(fd, (char)('0' | -(nb % 10)));
    } else {
        my_putpos(fd, abs_n);
    }
    return 0;
}
