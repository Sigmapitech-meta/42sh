/*
** EPITECH PROJECT, 2023
** printf
** File description:
** handle char
*/
#include <stdarg.h>
#include "epitech/printf.h"

int handle_uint(int fd, va_list args)
{
    unsigned int n = (unsigned int)va_arg(args, int);
    return put_nbr(fd, n);
}
