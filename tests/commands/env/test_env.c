/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_command_ls.c
*/

#include "sputnik.h"
#include "run_shell_command.h"

TEST_STD(run_shell_command, env)
$ {
    CR_ASSERT_EQ(run_shell_command("env"), 0);
}
