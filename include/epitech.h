/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** epitech.h
*/

#ifndef EPITECH_H
    #define EPITECH_H

    #include "utils/sentinel.h"

    #define EXIT_MSG(ret, written) SENTINEL_OR(written, ret)

    #define EXIT_KO_MSG(...) EXIT_MSG(EXIT_KO, EPRINTF(__VA_ARGS__))
    #define EXIT_OK_MSG(...) EXIT_MSG(EXIT_OK, printf(__VA_ARGS__))

typedef _Bool bool_t;
typedef struct _IO_FILE file_t;

enum {
    TRUE = 1,
    FALSE = 0
};

enum {
    EXIT_OK = 0,
    EXIT_KO = 84
};

#endif /* !EPITECH_H */
