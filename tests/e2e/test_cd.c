/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_cd.c
*/

#include "run_shell_command.h"
#include "sputnik.h"
#include "shell/shell.h"
#include "mocks/getline.h"

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

TEST_STD(run_command_cd, non_previous_dir)
$ {
    CTX_AUTOFREE context_t *ctx = run_shell_command("cd -");

    if (!ctx)
        CR_SKIP("Allocation error.");
    CR_ASSERT_EQ(ctx->status, EXIT_FAILURE);
    CR_ASSERT_STDERR_EQ_STR("-: Invalid argument\n");
}

static
void setup_mocks(void)
{
    static char *input = (
            "cd /;"
            "cd -;\n"
    );

    GETLINE_DATA->mode = TABLE;
    GETLINE_DATA->table = (char **)&input;
    redirect_all_std();
}

static
void teardown_mocks(void)
{
    GETLINE_DATA->mode = NORMAL;
}

TEST(run_command_cd, previous_dir, TEST_USE(setup_mocks, teardown_mocks))
$ {
    int ret;

    setbuf(stdout, 0);
    ret = shell_run_from_env(environ);
    CR_ASSERT_STDOUT_EQ_STR("");
    CR_ASSERT_STDERR_EQ_STR("");
    CR_ASSERT_EQ(ret, EXIT_OK);
}
