/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_which.c
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
    CTX_AUTOFREE context_t *ctx = run_shell_command("which ls");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, EXIT_OK);
    state = fread(buff, 1, 1023, fake_stdout);
    if (IS_SENTINEL_OF(state, ssize_t))
        cr_skip("Cannot read fake stdout");
    buff[state] = '\0';
    CR_ASSERT(
        strncmp(buff + state - 4, "/ls\n", 4),
        "Should end with `.../ls\n`."
    );
}

TEST_STD(run_command_which, builtin_command)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("which which");

    if (!ctx)
        CR_SKIP("Allocation error.");
    fflush(stdout);
    CR_ASSERT_STDOUT_EQ_STR("which: shell built-in command.\n");
}

TEST_STD(run_command_which, does_not_exist)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("which Ng89~!c@");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_STDERR_EQ_STR("Ng89~!c@: Command not found.\n");
    CR_ASSERT_EQ(ctx->status, EXIT_OK);
}


TEST_STD(run_command_which, not_path_set)
$ {
    CTX_AUTOFREE context_t *ctx;

    unsetenv("PATH");
    ctx = run_shell_command("which ls");
    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_STDERR_EQ_STR("ls: Command not found.\n");
    CR_ASSERT_EQ(ctx->status, EXIT_OK);
}
