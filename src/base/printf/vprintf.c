/*
** EPITECH PROJECT, 2023
** printf
** File description:
** vprintf function (printf with va_list)
*/
#include <stdarg.h>
#include "epitech/printf.h"

int w_vprintf(int fd, char *format, va_list args)
{
    char lookahead;

    if (!format)
        return (-1);
    for (int i = 0; format[i]; i++) {
        if (format[i] != '%') {
            w_putchar(fd, format[i]);
            continue;
        }
        lookahead = format[++i];
        if (!lookahead)
            return -1;
        handle_lookahead(fd, lookahead, args);
    }
    return 0;
}
