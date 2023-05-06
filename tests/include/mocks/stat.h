/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** stat.h
*/

#ifndef MOCK_stat_H_
    #define MOCK_stat_H_

    #define real_stat __real_stat
    #define wrap_stat __wrap_stat

    #define STAT_SWITCH (*switch_stat())
    #define BREAK_STAT .init RAW_EQ break_stat, .fini RAW_EQ fix_stat

typedef _Bool bool_t;
typedef struct {
    bool_t is_broken;
} sw_stat_t;

sw_stat_t *switch_stat(void);

void *wrap_stat(size_t size);
void *real_stat(size_t size);

void fix_stat(void);
void break_stat(void);

#endif /* !MOCK_STAT_H_ */
