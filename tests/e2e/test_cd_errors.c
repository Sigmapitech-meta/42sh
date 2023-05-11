/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_cd_errors.c
*/

#include "run_shell_command.h"
#include "sputnik.h"
#include "shell/shell.h"

TEST_STD(run_command_cd, move_to_a_file)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("cd Makefile");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, EXIT_FAILURE);
    CR_ASSERT_STDERR_EQ_STR("Makefile: Not a directory.\n");
}

TEST_STD(run_command_cd, cd_home_no_env)
$ {
    CTX_AUTOFREE context_t *ctx = NULL;

    unsetenv("HOME");
    ctx = run_shell_command("unsetenv HOME;cd");
    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_STDERR_EQ_STR("No $home variable set\n");
    CR_ASSERT_EQ(ctx->status, EXIT_FAILURE);
}

TEST_STD(run_command_cd, too_many_arguments)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("cd . .");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, EXIT_FAILURE);
    CR_ASSERT_STDERR_EQ_STR("cd: Too many arguments.\n");
}

TEST_STD(run_command_cd, move_invalid)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("cd ?");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, EXIT_FAILURE);
    CR_ASSERT_STDERR_EQ_STR("?: No such file or directory\n");
}
