/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_exit_fail_one.c
*/

#include "sputnik.h"
#include "run_shell_command.h"

TEST_STD(run_shell_command, exit_fail_one)
$ {
    CR_ASSERT_EQ(run_shell_command("exit 9 7 4"), 0);
    CR_ASSERT_STDERR_EQ_STR("exit: Expression Syntax.\n");
}
