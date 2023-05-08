/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** mock_read.c
*/

#include <unistd.h>

#include "epitech.h"
#include "mocks/read.h"

bool_t *switch_read(void)
{
    static bool_t state = FALSE;

    return &state;
}

ssize_t wrap_read(int fd, void *buff, ssize_t size)
{
    return (IS_READ_BROKEN) ? SENTINEL : real_read(fd, buff, size);
}

void fix_read(void)
{
    IS_READ_BROKEN = FALSE;
}

void break_read(void)
{
    IS_READ_BROKEN = TRUE;
}
