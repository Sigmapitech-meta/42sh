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

/** printf-like within the standard error */
    #define EPRINTF(...) (fprintf(stderr, __VA_ARGS__))

    #define NULL_OR(cond, expr) ((cond) ? expr : NULL)

typedef struct stat stat_t;

static inline
USED size_t get_line(char **line)
{
    static size_t zero = 0;

    return getline(line, &zero, stdin);
}

static inline
USED char *str_trans(char *string, char in, char out)
{
    for (int i = 0; string[i]; i++)
        if (string[i] == in)
            string[i] = out;
    return string;
}


int str_count_tok(char *string, char *delim);
char **str_split(char *string, char *delim);

char *file_read_fd(int fd, size_t filesize);
char *file_read(char const *filepath);

#endif /* !BASE_H_ */
