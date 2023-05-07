/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_is_debug_mode.c
*/

#include "coding_style_fix.h"
#include "sputnik.h"
#include "utils/debug_mode.h"

TEST(is_debug_mode, should_be_false)
$ {
    CR_ASSERT_NOT(is_debug_mode());
}
