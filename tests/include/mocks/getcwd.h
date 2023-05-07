/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** getcwd.h
*/

#ifndef MOCK_GETCWD_H_
    #define MOCK_GETCWD_H_

    #define real_getcwd __real_getcwd
    #define wrap_getcwd __wrap_getcwd

    #define IS_GETCWD_REPLACED (*switch_getcwd())

typedef _Bool bool_t;

bool_t *switch_getcwd(void);

void *wrap_getcwd(char *str);
void *real_getcwd(char *str);

void fix_getcwd(void);
void break_getcwd(void);

#endif /* !MOCK_GETCWD_H_ */
