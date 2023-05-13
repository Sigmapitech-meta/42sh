/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** mock_stat.c
*/

#include <unistd.h>

#include "base.h"
#include "epitech.h"
#include "mocks/stat.h"

bool_t *switch_stat(void)
{
    static bool_t state = FALSE;

    return &state;
}

int wrap_stat(const char *file, stat_t *buf)
{
    return (IS_STAT_BROKEN) ? SENTINEL : real_stat(file, buf);
}

void fix_stat(void)
{
    IS_STAT_BROKEN = FALSE;
}

void break_stat(void)
{
    IS_STAT_BROKEN = TRUE;
}
