/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_command_ls.c
*/

#include "epitech/sputnik.h"
#include "run_shell_command.h"

TEST_STD(run_shell_command, cd_not_dir)
$ {
    CR_ASSERT_EQ(run_shell_command("cd Makefile"), 1);
    CR_ASSERT_STDERR_EQ_STR("Makefile: Not a directory.\n");
}
