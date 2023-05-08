/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_whitespace.c
*/

#include "epitech.h"
#include "sputnik.h"
#include "mocks/getline.h"
#include "shell/shell.h"

static
void setup_mocks(void)
{
    static char *input = "     ;\t";

    GETLINE_DATA->mode = TABLE;
    GETLINE_DATA->table = (char **)&input;
    redirect_all_std();
}

static
void teardown_mocks(void)
{
    GETLINE_DATA->mode = NORMAL;
}

TEST(run_shell_command, whitespace, TEST_USE(setup_mocks, teardown_mocks))
$ {
    command_t cmd = { 0 };
    context_t ctx = { .is_running = TRUE, .cmd = &cmd };

    shell_run_from_ctx(&ctx);
    CR_ASSERT_EQ(ctx.status, EXIT_OK);
}
