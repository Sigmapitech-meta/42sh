/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_exit.c
*/

#include "sputnik.h"
#include "run_shell_command.h"

TEST_STD(run_shell_command, exit)
$ {
    CR_ASSERT_EQ(run_shell_command("exit"), 0);
    CR_ASSERT_STDOUT_EQ_STR("");
}
