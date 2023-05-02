/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** sputnik.h
*/

#ifndef SPUTNIK_H_
    #define SPUTNIK_H_

    #include <criterion/criterion.h>
    #include <criterion/redirect.h>

    #include "norm.h"
    #include "utils/attributes.h"

    #define TEST(...) Test(__VA_ARGS__)
    #define TEST_STD(...) Test(__VA_ARGS__, .init EQ redirect_all_std)

    #define CR_ASSERT(...) cr_assert(__VA_ARGS__)

    #define CR_ASSERT_EQ(...) cr_assert_eq(__VA_ARGS__)
    #define CR_ASSERT_STR_EQ(...) cr_assert_str_eq(__VA_ARGS__)

    #define CR_ASSERT_NEQ(...) cr_assert_neq(__VA_ARGS__)

    #define CR_ASSERT_STDOUT_EQ_STR(...) cr_assert_stdout_eq_str(__VA_ARGS__)


USED void redirect_all_std(void);

#endif /* !SPUTNIK_H_ */
