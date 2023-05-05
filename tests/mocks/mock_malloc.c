/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** mock_malloc.c
*/

#include <unistd.h>

#include "epitech.h"
#include "mocks/malloc.h"

sw_malloc_t *switch_malloc(void)
{
    static sw_malloc_t state = {0};

    return &state;
}

void *wrap_malloc(size_t size)
{
    if (MALLOC_SWITCH.is_broken) {
        MALLOC_SWITCH.last_allocated = 0;
        return NULL;
    } else {
        MALLOC_SWITCH.last_allocated = size;
        return real_malloc(size);
    }
}

void fix_malloc(void)
{
    MALLOC_SWITCH.is_broken = FALSE;
}

void break_malloc(void)
{
    MALLOC_SWITCH.is_broken = TRUE;
}
