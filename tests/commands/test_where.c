/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_where.c
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

static
void check_result(char *buff)
{
    char *rest;
    char *token = strtok_r(buff, "\n", &rest);

    CR_ASSERT(token);
    do {
        CR_ASSERT(
            strncmp(token + strlen(token) - 4, "/ls\n", 4),
            "Should end with `.../ls\n`."
        );
        token = strtok_r(NULL, "\n", &rest);
    } while(token);
}

TEST_STD(run_command_where, which)
$ {
    int state;
    char buff[1023] = { '\0' };
    file_t *fake_stdout = cr_get_redirected_stdout();
    CTX_AUTOFREE context_t *ctx = run_shell_command("where ls");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, EXIT_OK);
    fflush(stdout);
    state = fread(buff, 1, 1023, fake_stdout);
    if (IS_SENTINEL_OF(state, ssize_t))
        CR_SKIP("Cannot read fake stdout");
    buff[state] = '\0';
    check_result(buff);
    CR_ASSERT_EQ(ctx->status, EXIT_OK);
}
