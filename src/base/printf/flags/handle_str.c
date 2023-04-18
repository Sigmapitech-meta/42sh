/*
** EPITECH PROJECT, 2023
** printf
** File description:
** handle char
*/
#include <stdarg.h>
#include "epitech/printf.h"

int handle_str(int fd, va_list args)
{
    char *s = va_arg(args, char *);

    if (!s)
        return w_putstr(fd, "(null)");
    return w_putstr(fd, s);
}
