/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** mock_read.c
*/

#include <unistd.h>

#include "epitech.h"
#include "mocks/read.h"

sw_read_t *switch_read(void)
{
    static sw_read_t state = {0};

    return &state;
}

void *wrap_read(size_t size)
{
    return (READ_SWITCH.is_broken) ? NULL : real_read(size);
}

void fix_read(void)
{
    READ_SWITCH.is_broken = FALSE;
}

void break_read(void)
{
    READ_SWITCH.is_broken = TRUE;
}
