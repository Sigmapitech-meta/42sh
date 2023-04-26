/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** eprintf.c
*/

#include "printf_expansion.h"

/* printf-like within the standard error */
int eprintf(const char *fmt, ...)
{
    int ret;
    va_list args;

    va_start(args, fmt);
    ret = evprintf(fmt, args);
    va_end(args);
    return ret;
}
