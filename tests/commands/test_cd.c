/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_cd.c
*/

#include "sputnik.h"
#include "run_shell_command.h"

TEST_STD(run_shell_command, cd)
$ {
    CR_ASSERT_EQ(run_shell_command("cd src"), 0);
    CR_ASSERT_STDOUT_EQ_STR("");
}

TEST_STD(run_shell_command, cd_home)
$ {
    CR_ASSERT_EQ(run_shell_command("cd"), 0);
    CR_ASSERT_STDOUT_EQ_STR("");
}

TEST_STD(run_shell_command, cd_not_dir)
$ {
    CR_ASSERT_EQ(run_shell_command("cd Makefile"), 0);
    CR_ASSERT_STDERR_EQ_STR("Makefile: Not a directory.\n");
}

TEST_STD(run_shell_command, cd_root)
$ {
    CR_ASSERT_EQ(run_shell_command("cd /"), 0);
    CR_ASSERT_STDOUT_EQ_STR("");
}
