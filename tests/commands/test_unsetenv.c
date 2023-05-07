/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_unsetenv.c
*/

#include "sputnik.h"
#include "run_shell_command.h"

TEST_STD(run_command_unsetenv, remove_a_existing_value)
$ {
    CR_ASSERT_EQ(run_shell_command("unsetenv USER"), 0);
    CR_ASSERT_STDERR_EQ_STR("");
}

TEST_STD(run_command_unsetenv, remove_a_non_existing_value)
$ {
    CR_ASSERT_EQ(run_shell_command("unsetenv yousk2"), 0);
    CR_ASSERT_STDERR_EQ_STR("");
}

TEST_STD(run_command_unsetenv, not_enough_arguments)
$ {
    CR_ASSERT_EQ(run_shell_command("unsetenv"), 0);
    CR_ASSERT_STDERR_EQ_STR("unsetenv: Too few arguments.\n");
}
