/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_getline.c
*/

#include "epitech/sputnik.h"
#include "mocks/mock_getline.h"

#include "shell/utils.h"
#include "utils/autofree.h"

TEST(
    get_line, should_retrieve_the_user_input,
    TEST_USE(use_mock_getline, use_normal_getline)
)
$ {
    size_t size;
    AUTOFREE char *line = NULL;

    for (int i = 0; i < GETLINE_TABLE_LENGTH; i++) {
        size = get_line(&line);
        CR_ASSERT_EQ(size, strlen(GETlINE_TABLE[i]));
        CR_ASSERT_STR_EQ(line, GETlINE_TABLE[i]);
    }
}
