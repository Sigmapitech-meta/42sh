/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_setenv_invalid_names.c
*/

#include "sputnik.h"
#include "run_shell_command.h"
#include "shell/shell.h"

TEST_STD(run_command_setenv, invalid_name_starting_by_a_digit)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("setenv 2B2T");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, 1);
    CR_ASSERT_STDERR_EQ_STR(
        "setenv: Variable name must begin with a letter.\n"
    );
}

TEST_STD(run_command_setenv, invalid_name_starting_by_a_symbol)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("setenv @");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, 1);
    CR_ASSERT_STDERR_EQ_STR(
        "setenv: Variable name must begin with a letter.\n"
    );
}

TEST_STD(run_command_setenv, invalid_name_non_alphanum)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("setenv Y°sk2");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, 1);
    CR_ASSERT_STDERR_EQ_STR(
        "setenv: Variable name must contain alphanumeric characters.\n"
    );
}
