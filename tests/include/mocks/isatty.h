/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** isatty.h
*/

#ifndef MOCK_ISATTY_H_
    #define MOCK_ISATTY_H_

    #define real_isatty __real_isatty
    #define wrap_isatty __wrap_isatty

    #define SWITCH_IS_A_TTY (*switch_isatty())

typedef _Bool bool_t;

bool_t *switch_isatty(void);

bool_t wrap_isatty(int fd);
bool_t real_isatty(int fd);

void yes_is_atty(void);
void not_is_not_atty(void);

#endif /* !MOCK_ISATTY_H_ */
