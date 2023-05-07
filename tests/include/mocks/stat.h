/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** stat.h
*/

#ifndef MOCK_STAT_H_
    #define MOCK_STAT_H_

    #define real_stat __real_stat
    #define wrap_stat __wrap_stat

    #define IS_STAT_BROKEN (*switch_stat())

typedef _Bool bool_t;

bool_t *switch_stat(void);

void *wrap_stat(size_t size);
void *real_stat(size_t size);

void fix_stat(void);
void break_stat(void);

#endif /* !MOCK_STAT_H_ */
