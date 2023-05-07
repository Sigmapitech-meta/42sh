/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** mock_xxx.c
*/

#include <unistd.h>

#include "epitech.h"
#include "mocks/gethostname.h"

bool_t *switch_gethostname(void)
{
    static bool_t state = {0};

    return &state;
}

void wrap_gethostname(char *name, size_t len)
{
    if (!IS_GETHOSTNAME_BROKEN) {
        real_gethostname(name, len);
        return;
    }
    name[0] = '%';
    name[1] = 's';
    name[2] = '\0';
}

void fix_gethostname(void) {
    IS_GETHOSTNAME_BROKEN = FALSE;
}

void break_gethostname(void)
{
    IS_GETHOSTNAME_BROKEN = TRUE;
}
