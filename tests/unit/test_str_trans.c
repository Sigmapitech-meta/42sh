/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_evprintf.c
*/

#include "base.h"

#include "coding_style_fix.h"
#include "sputnik.h"

TEST(str_trans, translate_a_string)
$ {
    char src[] = "this is fine";
    char *out = str_trans(src, 'i', ' ');

    CR_ASSERT_STR_EQ(out, "th s  s f ne");
    CR_ASSERT_STR_EQ(str_trans(src, ' ', '_'), "th_s__s_f_ne");
}
