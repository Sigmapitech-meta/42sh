/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** epitech_criterion.h
*/

#ifndef EPITECH_CRITERION_H_
    #define EPITECH_CRITERION_H_

    #include <criterion/criterion.h>

    #define $ /* Fix the norm! */

    #define TEST(...) Test(__VA_ARGS__)

    #define CR_ASSERT(...) cr_assert(__VA_ARGS__)

    #define CR_ASSERT_EQ(...) cr_assert_eq(__VA_ARGS__)
    #define CR_ASSERT_STR_EQ(...) cr_assert_str_eq(__VA_ARGS__)

    #define CR_ASSERT_NEQ(...) cr_assert_neq(__VA_ARGS__)

    #define CR_ASSERT_STDOUT_EQ_STR(...) cr_assert_stdout_eq_str(__VA_ARGS__)

#endif /* !EPITECH_CRITERION_H_ */
