/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_command_ls.c
*/

#include "sputnik.h"
#include "run_shell_command.h"

TEST_STD(run_shell_command, setenv_fail_one)
$ {
    CR_ASSERT_EQ(run_shell_command("setenv 2B2T"), 0);
    CR_ASSERT_STDERR_EQ_STR("setenv: Variable name must begin with a letter.\n");
}
