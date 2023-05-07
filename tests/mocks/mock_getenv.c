/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** mock_getenv.c
*/


#include <string.h>
#include "epitech.h"
#include "mocks/getenv.h"

bool_t *switch_getenv(void)
{
    static bool_t state = {0};

    return &state;
}

void *wrap_getenv(char *string)
{
    return (IS_GETENV_REPLACED) ? strdup("%s") : real_getenv(string);
}

void fix_getenv(void)
{
    IS_GETENV_REPLACED = FALSE;
}

void break_getenv(void)
{
    IS_GETENV_REPLACED = TRUE;
}
