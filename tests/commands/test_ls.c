/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_ls.c
*/

#include "sputnik.h"
#include "run_shell_command.h"
#include "shell/shell.h"

TEST_STD(run_command_ls, ls)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("ls Makefile");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, 0);
    CR_ASSERT_STDOUT_EQ_STR("Makefile\n");
}
