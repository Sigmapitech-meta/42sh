/*
** EPITECH PROJECT, 2023
** File description:
** test_which_fail.c
*/

#include <unistd.h>

#include "epitech.h"
#include "sputnik.h"

#include "run_shell_command.h"
#include "shell/shell.h"
#include "utils/sentinel.h"

TEST_STD(run_command_which, no_argument)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("which");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_STDERR_EQ_STR("which: Too few arguments.\n");
    CR_ASSERT_EQ(ctx->status, 1);
}

TEST_STD(run_command_which, simple_ls)
$ {
    int state;
    char buff[1024] = { '\0' };
    file_t *fake_stdout = cr_get_redirected_stdout();
    CTX_AUTOFREE context_t *ctx = run_shell_command("which");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, EXIT_OK);
    state = read(fake_stdout->_fileno, buff, 1023);
    if (IS_SENTINEL_OF(state, ssize_t))
        cr_skip("Cannot read fake stdout");
    buff[state] = '\0';
    CR_ASSERT(
        strncmp(buff + state - 4, "/ls\n", 2),
        "Should end with `.../ls\n`."
    );
}

TEST_STD(run_command_which, builtin_command)
$ {
    int state;
    char buff[1024] = { '\0' };
    CTX_AUTOFREE context_t *ctx = run_shell_command("which which");
    file_t *fake_stdout = cr_get_redirected_stdout();

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, EXIT_OK);
    state = read(fake_stdout->_fileno, buff, 1023);
    if (IS_SENTINEL_OF(state, ssize_t))
        cr_skip("Cannot read fake stdout");
    buff[state] = '\0';
    CR_ASSERT(
        strncmp(buff + state - 4, "/ls\n", 2),
        "which: shell built-in command."
    );
}
