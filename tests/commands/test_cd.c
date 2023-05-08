/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_cd.c
*/

#include "epitech.h"
#include "run_shell_command.h"
#include "sputnik.h"
#include "shell/shell.h"

TEST_STD(run_command_cd, move_to_folder)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("cd src");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, EXIT_OK);
    CR_ASSERT_STDOUT_EQ_STR("");
}

TEST_STD(run_command_cd, cd_home)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("cd");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, EXIT_OK);
    CR_ASSERT_STDOUT_EQ_STR("");
}

TEST_STD(run_command_cd, cd_root)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("cd /");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, EXIT_OK);
    CR_ASSERT_STDOUT_EQ_STR("");
}

TEST_STD(run_command_cd, cd_relative)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("cd ~/../../../../bin");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, EXIT_OK);
}

TEST_STD(run_command_cd, previous_dir)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("cd -");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, EXIT_OK);
}
