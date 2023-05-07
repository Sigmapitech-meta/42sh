/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_getenv.c
*/

#include "run_shell_command.h"
#include "sputnik.h"
#include "utils/debug_mode.h"

TEST_STD(run_command_getenv, should_do_stuff)
$ {
    CTX_AUTOFREE context_t *ctx = NULL;

    if (!is_debug_mode())
        CR_SKIP("Debug only test.");
    ctx = run_shell_command("setenv a b; getenv a");
    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_STDOUT_EQ_STR("--- a ---\nb");
}
