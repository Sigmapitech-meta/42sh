/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_restricted_path.c
*/

#include "epitech.h"
#include "run_shell_command.h"
#include "sputnik.h"
#include "shell/shell.h"

TEST_STD(run_command_kek, restricted_path)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("setenv PATH /abc; kek");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_STDERR_EQ_STR("kek: Command not found.\n");
    CR_ASSERT_EQ(ctx->status, EXIT_FAILURE);
}

TEST_STD(run_command_kek, empty_path)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("setenv PATH; kek");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_STDERR_EQ_STR("kek: Command not found.\n");
    CR_ASSERT_EQ(ctx->status, EXIT_FAILURE);
}
