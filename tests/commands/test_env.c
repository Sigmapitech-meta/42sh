/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_env.c
*/

#include "epitech.h"
#include "sputnik.h"
#include "run_shell_command.h"
#include "shell/shell.h"

TEST_STD(run_shell_command, env)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("env");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, EXIT_OK);
}
