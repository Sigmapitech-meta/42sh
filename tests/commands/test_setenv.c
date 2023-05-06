/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_setenv.c
*/

#include "epitech.h"
#include "sputnik.h"
#include "run_shell_command.h"

TEST_STD(run_shell_command, echo_foo)
$ {
    CR_ASSERT_EQ(run_shell_command("echo foo"), EXIT_OK);
    CR_ASSERT_STDOUT_EQ_STR("foo\n");
}
