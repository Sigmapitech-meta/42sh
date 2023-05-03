/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_command_not_found.c
*/

#include "epitech/sputnik.h"
#include "run_shell_command.h"

TEST_STD(run_shell_command, command_not_found)
$ {
    CR_ASSERT_EQ(run_shell_command("aaa"), 1);
    CR_ASSERT_STDERR_EQ_STR("aaa: Command not found.\n");
}
