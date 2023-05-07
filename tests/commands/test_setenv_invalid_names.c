/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_setenv_invalid_names.c
*/

#include "sputnik.h"
#include "run_shell_command.h"

TEST_STD(run_command_setenv, invalid_name_starting_by_a_digit)
$ {
    CR_ASSERT_EQ(run_shell_command("setenv 2B2T"), 0);
    CR_ASSERT_STDERR_EQ_STR(
        "setenv: Variable name must begin with a letter.\n"
    );
}

TEST_STD(run_command_setenv, invalid_name_starting_by_a_symbol)
$ {
    CR_ASSERT_EQ(run_shell_command("setenv @"), 0);
    CR_ASSERT_STDERR_EQ_STR(
        "setenv: Variable name must begin with a letter.\n"
    );
}

TEST_STD(run_command_setenv, invalid_name_non_alphanum)
$ {
    CR_ASSERT_EQ(run_shell_command("setenv Y°sk2"), 0);
    CR_ASSERT_STDERR_EQ_STR(
        "setenv: Variable name must contain alphanumeric characters.\n"
    );
}