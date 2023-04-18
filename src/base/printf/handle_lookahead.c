/*
** EPITECH PROJECT, 2023
** printf
** File description:
** handle char
*/

#include <stdarg.h>
#include "epitech/printf.h"

const conv_spec_t CONV_SPECS[] = {
    {'d', &handle_int},
    {'i', &handle_int},
    {'c', &handle_chr},
    {'s', &handle_str},
    {'u', &handle_uint}
};
const int CONV_SP_LEN = sizeof(CONV_SPECS) / sizeof(CONV_SPECS[0]);

int handle_lookahead(int fd, char lookahead, va_list args)
{
    for (int i = 0; i < CONV_SP_LEN; i++) {
        if (CONV_SPECS[i].name == lookahead) {
            return CONV_SPECS[i].handler(fd, args);
        }
    }
    if (lookahead != '%')
        w_putchar(fd, '%');
    w_putchar(fd, lookahead);
    return 2;
}
