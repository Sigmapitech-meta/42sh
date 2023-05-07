/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_exit_value.c
*/

#include "sputnik.h"
#include "run_shell_command.h"

TEST_STD(run_shell_command, exit_value)
$ {
    CR_ASSERT_EQ(run_shell_command("exit 42"), 42);
    CR_ASSERT_STDERR_EQ_STR("");
}
