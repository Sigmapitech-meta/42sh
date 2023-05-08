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

TEST_STD(run_shell_command, not_home_set)
$ {
    context_t *ctx;

    unsetenv("HOME");
    ctx = run_shell_command("~/foo");
    if (!ctx)
        CR_SKIP("Memory Allocation.");
    CR_ASSERT_EQ(ctx->status, EXIT_FAILURE);
    CR_ASSERT_STDERR_EQ_STR("No $home variable set\n");
}

TEST_STD(run_shell_command, invalid_pipe)
$ {
    context_t *ctx = run_shell_command("ls -alr |;");

    if (!ctx)
        CR_SKIP("Memory Allocation.");
    CR_ASSERT_EQ(ctx->status, EXIT_FAILURE);
    CR_ASSERT_STDERR_EQ_STR("Invalid null command.\n");
}

TEST_STD(run_shell_command, wrong_architecture)
$ {
    context_t *ctx = run_shell_command("./tests/fixtures/test_file");

    if (!ctx)
        CR_SKIP("Memory Allocation.");
    CR_ASSERT_EQ(ctx->status, EXIT_FAILURE);
    CR_ASSERT_STDERR_EQ_STR(
        "./tests/fixtures/test_file: Exec format error. Wrong Architecture.\n"
    );
}
