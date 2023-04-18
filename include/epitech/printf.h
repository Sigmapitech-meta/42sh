/*
** EPITECH PROJECT, 2023
** printf
** File description:
** header file for printf functions
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

    #include <stdarg.h>

// Core functions

int w_printf(int fd, char *format, ...);
int w_vprintf(int fd, char *format, va_list args);
int handle_lookahead(int fd, char lookahead, va_list args);

int handle_int(int fd, va_list args);
int handle_chr(int fd, va_list args);
int handle_str(int fd, va_list args);
int handle_uint(int fd, va_list args);

typedef struct {
    char name;
    int (*handler)(int fd, va_list ap);
} conv_spec_t;

int put_nbr(int fd, int nb);

int w_putchar(int fd, char c);
int w_putstr(int fd, char *str);
#endif
