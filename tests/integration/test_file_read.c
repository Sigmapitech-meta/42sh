/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_file_read.c
*/

#include <criterion/criterion.h>

#include "base.h"
#include "sputnik.h"

#include "mocks/read.h"
#include "mocks/malloc.h"
#include "mocks/stat.h"

TEST(read_file, can_read_a_file)
$ {
    CR_ASSERT_STR_EQ(
        file_read("tests/fixtures/test_file"),
        "Hello my name is Albert\n"
    );
}

TEST(read_file, non_existent_file)
$ {
    CR_ASSERT_EQ(file_read("dont.exist"), NULL);
}

TEST(read_file, broken_malloc, TEST_USE(break_malloc, fix_malloc))
$ {
    CR_ASSERT_EQ(
        file_read("tests/fixtures/test_file"),
        NULL
    );
}

TEST(read_file, broken_read, TEST_USE(break_read, fix_read))
$ {
    CR_ASSERT_EQ(
        file_read("tests/fixtures/test_file"),
        NULL
    );
}

TEST(read_file, broken_stat, TEST_USE(break_stat, fix_stat))
$ {
    CR_ASSERT_EQ(
        file_read("tests/fixtures/test_file"),
        NULL
    );
}
