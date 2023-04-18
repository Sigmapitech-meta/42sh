/*
** EPITECH PROJECT, 2023
** printf
** File description:
** handle char
*/

#include <stdarg.h>
#include "epitech/printf.h"

int handle_int(int fd, va_list args)
{
    int n = va_arg(args, int);
    return put_nbr(fd, n);
}
