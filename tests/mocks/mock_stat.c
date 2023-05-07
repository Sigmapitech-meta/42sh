/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** mock_stat.c
*/

#include <unistd.h>

#include "epitech.h"
#include "mocks/stat.h"

bool_t *switch_stat(void)
{
    static bool_t state = FALSE;

    return &state;
}

void *wrap_stat(size_t size)
{
    return (IS_STAT_BROKEN) ? NULL : real_stat(size);
}

void fix_stat(void)
{
    IS_STAT_BROKEN = FALSE;
}

void break_stat(void)
{
    IS_STAT_BROKEN = TRUE;
}
