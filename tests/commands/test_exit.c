/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_exit.c
*/

#include "sputnik.h"
#include "run_shell_command.h"
#include "epitech.h"
#include "shell/shell.h"

TEST_STD(run_command_exit, exit_wtih_no_arguments)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("exit");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, EXIT_OK);
    CR_ASSERT_NOT(ctx->is_running);
}

TEST_STD(run_command_exit, too_many_arguments)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("exit 9 7 4");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, EXIT_FAILURE);
    CR_ASSERT_STDERR_EQ_STR("exit: Expression Syntax.\n");
}

TEST_STD(run_command_exit, passing_a_custom_value)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("exit 42");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, 42);
    CR_ASSERT_STDERR_EQ_STR("");
}

TEST_STD(run_command_exit, passing_a_non_digit_value)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("exit tamaman");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, 1);
    CR_ASSERT_STDERR_EQ_STR("exit: Expression Syntax.\n");
}
