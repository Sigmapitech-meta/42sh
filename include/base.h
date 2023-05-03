/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** base.h
*/

#ifndef BASE_H_
    #define BASE_H_

#include <stdio.h>
#include <unistd.h>
#include "utils/attributes.h"

/* vprintf-like within the standard error */
static inline
USED int evprintf(const char *fmt, va_list args)
{
    return vdprintf(STDERR_FILENO, fmt, args);
}

int eprintf(const char *fmt, ...);

int str_count(char *string, char *delim);
char **str_split(char *string, char *delim);
char *str_trans(char *string, char in, char out);

long file_get_size(char const *filepath);
char *file_read_fd(int fd, long filesize);
char *file_read(char *filepath);

size_t get_line(char **line);

#endif /* !BASE_H_ */
