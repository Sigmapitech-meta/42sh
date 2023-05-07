/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_which_fail.c
*/

#include <unistd.h>
#include "sputnik.h"
#include "run_shell_command.h"

TEST_STD(run_command_which, no_argument)
$ {
    CR_ASSERT_EQ(run_shell_command("which"), 0);
    CR_ASSERT_STDERR_EQ_STR("which: Too few arguments.\n");
}

TEST_STD(run_command_which, simple_ls)
$ {
    CR_ASSERT_EQ(run_shell_command("which ls"), 0);
    CR_ASSERT_STDOUT_EQ_STR("/usr/bin/ls\n");
}
