/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_unsetenv_nea.c
*/

#include "sputnik.h"
#include "run_shell_command.h"

TEST_STD(run_shell_command, unsetenv_nea)
$ {
    CR_ASSERT_EQ(run_shell_command("unsetenv"), 0);
    CR_ASSERT_STDERR_EQ_STR("unsetenv: Too few arguments.\n");
}
