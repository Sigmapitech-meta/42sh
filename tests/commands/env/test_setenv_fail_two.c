/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_command_ls.c
*/

#include "sputnik.h"
#include "run_shell_command.h"

TEST_STD(run_shell_command, setenv_fail_two)
$ {
    CR_ASSERT_EQ(run_shell_command("setenv Y°sk2"), 0);
    CR_ASSERT_STDERR_EQ_STR("setenv: Variable name must contain alphanumeric characters.\n");
}
