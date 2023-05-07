/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_where_fail.c
*/

#include <unistd.h>

#include "epitech.h"
#include "sputnik.h"

#include "run_shell_command.h"
#include "shell/shell.h"
#include "utils/sentinel.h"

TEST_STD(run_command_where, no_arguments)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("where");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_STDERR_EQ_STR("where: Too few arguments.\n");
    CR_ASSERT_EQ(ctx->status, 1);
}

TEST_STD(run_command_where, ls)
$ {
    int read;
    int count = 0;
    char *buff;
    file_t *fake_stdout = cr_get_redirected_stdout();
    CTX_AUTOFREE context_t *ctx = run_shell_command("which ls");
    size_t track = 0;

    if (!ctx)
        CR_SKIP("Allocation error.");
    do {
        read = getline(&buff, &track, fake_stdout);
        if (IS_SENTINEL_OF(read, ssize_t))
            break;
        CR_ASSERT(
            strncmp(buff + read - 4, "/ls\n", 2),
            "Should end with `.../ls\n`.");
    } while (++count);
    if (!count)
        CR_SKIP("Cannot read fake stdout");
    CR_ASSERT_EQ(ctx->status, EXIT_OK);
}
