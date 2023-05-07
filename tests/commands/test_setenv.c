/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_setenv.c
*/

#include "epitech.h"
#include "sputnik.h"
#include "run_shell_command.h"
#include "shell/shell.h"

TEST(run_command_setenv, yousk2_to_couscous)
$ {
    context_t *ctx = run_shell_command("setenv Yousk2 couscous");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, EXIT_OK);
    CR_ASSERT_STR_EQ(getenv("Yousk2"), "couscous");
}

TEST(run_command_setenv, already_defined_env_variable)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("setenv USER Yousk2");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, EXIT_OK);
    CR_ASSERT_STR_EQ(getenv("USER"), "Yousk2");
}

TEST_STD(run_command_setenv, setenv_no_arg)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("setenv");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, EXIT_OK);
}

TEST_STD(run_command_setenv, too_many_arguments)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command(
        "setenv Yousk2 robert couscous"
    );

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, 1);
    CR_ASSERT_STDERR_EQ_STR("setenv: Too many arguments.\n");
}
