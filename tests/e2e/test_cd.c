/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_command_ls.c
*/

#include "epitech/sputnik.h"
#include "run_shell_command.h"

TEST_STD(run_shell_command, cd)
$ {
    CR_ASSERT_EQ(run_shell_command("cd tests/fixtures/admin; ls"), 0);
    CR_ASSERT_STDOUT_EQ_STR("root\n");
}
