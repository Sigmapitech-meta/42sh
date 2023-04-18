/*
** EPITECH PROJECT, 2023
** printf
** File description:
** handle char
*/

#include <stdarg.h>
#include "epitech/printf.h"

int handle_chr(int fd, va_list args)
{
    char n = (char)va_arg(args, int);

    return w_putchar(fd, (char)n);
}
