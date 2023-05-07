/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_setenv.c
*/

#include "sputnik.h"
#include "run_shell_command.h"

TEST_STD(run_shell_command, setenv_no_arg)
$ {
    CR_ASSERT_EQ(run_shell_command("setenv"), 0);
}
