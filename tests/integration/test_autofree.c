/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_autofree.c
*/

#include "sputnik.h"

#include "mocks/getline.h"
#include "utils/cleanup.h"

static
void is_ptr_null(char *ptr)
{
    setbuf(stdout, 0);
    printf("%s", (ptr) ? "no" : "yes");
}

TEST_STD(autofree, malloced)
$ {
    AUTOFREE char *dup = strdup("hello world!");

    if (!dup)
        return;
    is_ptr_null(dup);
    CR_ASSERT_STDOUT_EQ_STR("no");
}

TEST_STD(autofree, null)
$ {
    AUTOFREE char *ptr = NULL;

    is_ptr_null(ptr);
    CR_ASSERT_STDOUT_EQ_STR("yes");
}
