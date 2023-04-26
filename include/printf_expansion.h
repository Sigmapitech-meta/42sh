/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** printf_expansion.h
*/
#ifndef PRINTF_EXPANSION_H_
    #define PRINTF_EXPANSION_H_

    #include <stdarg.h>
    #include <stdio.h>
    #include <unistd.h>

int eprintf(const char *fmt, ...);

/* vprintf-like within the standard error */
static inline int evprintf(const char *fmt, va_list args)
{
    return vdprintf(STDERR_FILENO, fmt, args);
}

#endif /* !PRINTF_EXPANSION_H_ */
