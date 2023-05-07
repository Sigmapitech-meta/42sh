/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_setenv_getenv.c
*/

#include "run_shell_command.h"
#include "sputnik.h"
#include "utils/debug_mode.h"

TEST_STD(run_command_getenv, should_do_stuff)
{
    if (!is_debug_mode())
        cr_skip();
    run_shell_command("setenv a b; getenv a");
    CR_ASSERT_STDOUT_EQ_STR("--- a ---\nb");
}
