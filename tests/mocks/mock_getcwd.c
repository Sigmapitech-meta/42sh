/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** mock_getcwd.c
*/

#include <string.h>
#include "epitech.h"
#include "mocks/getcwd.h"

bool_t *switch_getcwd(void)
{
    static bool_t state = {0};

    return &state;
}

void *wrap_getcwd(char *name)
{
    return (IS_GETCWD_REPLACED) ? strdup("%s") : real_getcwd(name);
}

void fix_getcwd(void)
{
    IS_GETCWD_REPLACED = FALSE;
}

void break_getcwd(void)
{
    IS_GETCWD_REPLACED = TRUE;
}
