/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_command_ls.c
*/

#include "epitech/sputnik.h"
#include "run_shell_command.h"

TEST_STD(run_shell_command, setenv_tma)
$ {
    CR_ASSERT_EQ(run_shell_command("setenv Yousk2 robert couscous"), 0);
    CR_ASSERT_STDERR_EQ_STR("setenv: Too many arguments.\n");
}
