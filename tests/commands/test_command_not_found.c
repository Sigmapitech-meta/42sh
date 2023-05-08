/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_command_not_found.c
*/

#include "sputnik.h"
#include "run_shell_command.h"
#include "shell/shell.h"
#include "mocks/getline.h"

TEST_STD(run_shell_command, not_found_command)
$ {
    context_t *ctx = run_shell_command("MgkJNai9w£b");

    if (!ctx)
        CR_SKIP("Memory Allocation.");
    CR_ASSERT_EQ(ctx->status, EXIT_FAILURE);
    CR_ASSERT_STDERR_EQ_STR("MgkJNai9w£b: Command not found.\n");
}

TEST_STD(run_shell_command, home_not_found_command)
$ {
    context_t *ctx = run_shell_command("~/MgkJNai9w£b");

    if (!ctx)
        CR_SKIP("Memory Allocation.");
    CR_ASSERT_EQ(ctx->status, EXIT_FAILURE);
    CR_ASSERT_STDERR_EQ_STR("~/MgkJNai9w£b: Command not found.\n");
}

TEST_STD(run_shell_command, root_not_found_command)
$ {
    context_t *ctx = run_shell_command("/MgkJNai9w£b");

    if (!ctx)
        CR_SKIP("Memory Allocation.");
    CR_ASSERT_EQ(ctx->status, EXIT_FAILURE);
    CR_ASSERT_STDERR_EQ_STR("/MgkJNai9w£b: Command not found.\n");
}

TEST_STD(run_shell_command, relative_not_found_command)
$ {
    context_t *ctx = run_shell_command("./MgkJNai9w£b");

    if (!ctx)
        CR_SKIP("Memory Allocation.");
    CR_ASSERT_EQ(ctx->status, EXIT_FAILURE);
    CR_ASSERT_STDERR_EQ_STR("./MgkJNai9w£b: Command not found.\n");
}
