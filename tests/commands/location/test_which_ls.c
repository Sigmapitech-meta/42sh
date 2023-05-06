/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_which_ls.c
*/

#include "sputnik.h"
#include "run_shell_command.h"

TEST_STD(run_shell_command, which_ls)
$ {
    CR_ASSERT_EQ(run_shell_command("which ls"), 0);
    CR_ASSERT_STDOUT_EQ_STR("/usr/bin/ls\n");
}
