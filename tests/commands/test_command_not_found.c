/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_command_not_found.c
*/

#include "sputnik.h"
#include "run_shell_command.h"
#include "shell/shell.h"

TEST_STD(run_shell_command, command_not_found)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("aaa");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, EXIT_FAILURE);
    CR_ASSERT_STDERR_EQ_STR("aaa: Command not found.\n");
}
