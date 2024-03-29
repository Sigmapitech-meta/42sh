/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_str_split.c
*/

#include "base.h"
#include "coding_style_fix.h"
#include "sputnik.h"

#include "mocks/malloc.h"

TEST(str_split, this_is_fine_space)
$ {
    char src[] = "this is fine";
    char **words = str_split(src, " ");

    CR_ASSERT(words);
    CR_ASSERT_STR_EQ(words[0], "this");
    CR_ASSERT_STR_EQ(words[1], "is");
    CR_ASSERT_STR_EQ(words[2], "fine");
}

TEST(str_split, broken_malloc, TEST_USE(break_malloc, fix_malloc))
$ {
    char src[] = "magic happens";
    char **words = str_split(src, " ");

    CR_ASSERT_NOT(words);
}
