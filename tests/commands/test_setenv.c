/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_setenv.c
*/

#include "epitech.h"
#include "sputnik.h"
#include "run_shell_command.h"

TEST_STD(run_command_setenv, yousk2_to_couscous)
$ {
    CR_ASSERT_EQ(run_shell_command("setenv Yousk2 couscous"), EXIT_OK);
    CR_ASSERT_STDERR_EQ_STR("");
}

TEST_STD(run_command_setenv, already_defined_env_variable)
$ {
    CR_ASSERT_EQ(run_shell_command("setenv USER Yousk2"), 0);
    CR_ASSERT_STDERR_EQ_STR("");
}

TEST_STD(run_command_setenv, setenv_no_arg)
$ {
    CR_ASSERT_EQ(run_shell_command("setenv"), 0);
}

TEST_STD(run_command_setenv, too_many_arguments)
$ {
    CR_ASSERT_EQ(run_shell_command("setenv Yousk2 robert couscous"), 0);
    CR_ASSERT_STDERR_EQ_STR("setenv: Too many arguments.\n");
}
