/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** base.h
*/

#ifndef BASE_H_
    #define BASE_H_

/**
 * @file base.h
 * @author Gabriel Hosquet (gabriel.hosquet@epitech.eu)
 * @author Yohann Boniface (edhyjox@gmail.com)
 * @version 0.1
 *
 */

    #include <stdio.h>
    #include <unistd.h>
    #include "utils/attributes.h"

/** @brief printf-like within the standard error */
    #define EPRINTF(...) (fprintf(stderr, __VA_ARGS__))

/** @brief do the expression if cond is not NULL */
    #define NULL_OR(cond, expr) ((cond) ? expr : NULL)

typedef struct stat stat_t;

/**
 * @brief retrieve a line from the stdin
 *
 * @param line a pointer to the line
 */
static inline
USED size_t get_line(char **line)
{
    static size_t zero = 0;

    return getline(line, &zero, stdin);
}

/** @brief Translate a string */
static inline
USED char *str_trans(char *string, char in, char out)
{
    for (int i = 0; string[i]; i++)
        if (string[i] == in)
            string[i] = out;
    return string;
}


/** @brief Count the number of tokens in a string */
int str_count_tok(char *string, char *delim);
/** @brief Split a string */
char **str_split(char *string, char *delim);
/** @brief Split n string */
char **str_nsplit(char *string, char *delim, int n);

/** @brief Replace a string */
char *str_replace(char *src, char *from, char *to);
/** @brief Replace n char in a string */
char *str_nreplace(char *src, char *from, char *to, int n);
/** @brief Count the number of char in a string */
int str_count(char *src, char *from);

/** @brief Read a file */
char *file_read_fd(int fd, size_t filesize);
/** @brief Read a file without fd */
char *file_read(char const *filepath);

#endif /* !BASE_H_ */
