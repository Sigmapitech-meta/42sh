/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_unsetenv.c
*/

#include "epitech.h"
#include "sputnik.h"
#include "run_shell_command.h"
#include "shell/shell.h"

TEST_STD(run_command_unsetenv, remove_a_non_existing_value)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("unsetenv yousk2");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, EXIT_OK);
    CR_ASSERT_NOT(getenv("yousk2"));
}

TEST_STD(run_command_unsetenv, not_enough_arguments)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("unsetenv");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, 1);
    CR_ASSERT_STDERR_EQ_STR("unsetenv: Too few arguments.\n");
}
