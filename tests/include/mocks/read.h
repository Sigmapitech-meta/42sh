/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** read.h
*/

#ifndef MOCK_read_H_
    #define MOCK_read_H_

    #define real_read __real_read
    #define wrap_read __wrap_read

    #define IS_READ_BROKEN (*switch_read())

typedef _Bool bool_t;

bool_t *switch_read(void);

ssize_t wrap_read(int fd, void *buff, ssize_t size);
ssize_t real_read(int fd, void *buff, ssize_t size);

void fix_read(void);
void break_read(void);

#endif /* !MOCK_READ_H_ */
