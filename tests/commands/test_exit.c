/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_exit.c
*/

#include "sputnik.h"
#include "run_shell_command.h"
#include "epitech.h"

TEST_STD(run_command_exit, exit_wtih_no_arguments)
$ {
    CR_ASSERT_EQ(run_shell_command("exit"), EXIT_OK);
    CR_ASSERT_STDOUT_EQ_STR("");
}

TEST_STD(run_command_exit, too_many_arguments)
$ {
    CR_ASSERT_EQ(run_shell_command("exit 9 7 4"), 0);
    CR_ASSERT_STDERR_EQ_STR("exit: Expression Syntax.\n");
}

TEST_STD(run_command_exit, passing_a_custom_value)
$ {
    CR_ASSERT_EQ(run_shell_command("exit 42"), 42);
    CR_ASSERT_STDERR_EQ_STR("");
}

TEST_STD(run_command_exit, passing_a_non_digit_value)
$ {
    CR_ASSERT_EQ(run_shell_command("exit tamaman"), 0);
    CR_ASSERT_STDERR_EQ_STR("exit: Expression Syntax.\n");
}
