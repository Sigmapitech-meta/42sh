/*
** EPITECH PROJECT, 2023
** Kepler
** File description:
** mock_stat.c
*/

#include <unistd.h>

#include "epitech.h"
#include "mocks/stat.h"

sw_stat_t *switch_stat(void)
{
    static sw_stat_t state = {0};

    return &state;
}

void *wrap_stat(size_t size)
{
    return (STAT_SWITCH.is_broken) ? NULL : real_stat(size);
}

void fix_stat(void)
{
    STAT_SWITCH.is_broken = FALSE;
}

void break_stat(void)
{
    STAT_SWITCH.is_broken = TRUE;
}
