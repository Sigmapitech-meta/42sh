/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_setenv_already.c
*/

#include "sputnik.h"
#include "run_shell_command.h"

TEST_STD(run_shell_command, setenv_Yousk2)
$ {
    CR_ASSERT_EQ(run_shell_command("setenv USER Yousk2"), 0);
    CR_ASSERT_STDERR_EQ_STR("");
}
