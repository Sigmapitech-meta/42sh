/*
** EPITECH PROJECT, 2023
** printf
** File description:
** Core printf function
*/
#include <stdarg.h>
#include "epitech/printf.h"

int w_printf(int fd, char *format, ...)
{
    int ret;
    va_list args;

    va_start(args, format);
    ret = w_vprintf(fd, format, args);
    va_end(args);
    return ret;
}
