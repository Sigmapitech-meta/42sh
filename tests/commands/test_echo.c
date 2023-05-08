/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_cd.c
*/

#include "run_shell_command.h"
#include "sputnik.h"
#include "shell/shell.h"

TEST_STD(run_shell_command, echo)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("echo owo");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_STDOUT_EQ_STR("owo\n");
}
