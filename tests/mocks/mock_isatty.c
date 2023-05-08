/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** mock_isatty.c
*/

#include "epitech.h"
#include "mocks/isatty.h"
#include "utils/attributes.h"

bool_t *switch_isatty(void)
{
    static bool_t state = FALSE;

    return &state;
}

bool_t wrap_isatty(int fd UNUSED)
{
    return SWITCH_IS_A_TTY;
}

void yes_is_atty(void)
{
    SWITCH_IS_A_TTY = TRUE;
}

void not_is_not_atty(void)
{
    SWITCH_IS_A_TTY = FALSE;
}
