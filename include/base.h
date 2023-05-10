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

/** @brief Get the input source `FILE *` */
    #define GET_SOURCE_LOCATION (*source_location())

/** @brief retrieve the fd from a `FILE *` */
    #define fd _fileno

typedef struct stat stat_t;
typedef FILE file_t;

/** @brief Translate a string */
static inline
USED char *str_trans(char *string, char in, char out)
{
    for (int i = 0; string[i]; i++)
        if (string[i] == in)
            string[i] = out;
    return string;
}

/**
 * @brief retrieve a line from a file *
 * Defaults to stdin if set_getline_source is not called.
 * @param line a pointer to the line
 */
size_t get_line(char **line);

/** @brief set the `FILE *` the getline will read from. */
void set_getline_source(file_t *file);

/** @brief retrieve the a pointer to the `File *` getline reads from. */
file_t **source_location(void);

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
