/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** getenv.h
*/

#ifndef MOCK_GETENV_H_
    #define MOCK_GETENV_H_

    #define real_getenv __real_getenv
    #define wrap_getenv __wrap_getenv

    #define IS_GETENV_REPLACED (*switch_getenv())

typedef _Bool bool_t;

bool_t *switch_getenv(void);

void *wrap_getenv(char *str);
void *real_getenv(char *str);

void fix_getenv(void);
void break_getenv(void);

#endif /* !MOCK_GETENV_H_ */
