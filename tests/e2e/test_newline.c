/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_newline.c
*/

#include "sputnik.h"
#include "shell/shell.h"
#include "epitech.h"
#include "mocks/getline.h"

static
void setup_mocks(void)
{
    static char *input = "\n";

    GETLINE_DATA->mode = TABLE;
    GETLINE_DATA->table = (char **)&input;
    redirect_all_std();
}

static
void teardown_mocks(void)
{
    GETLINE_DATA->mode = NORMAL;
}

TEST(run_shell_command, newline, TEST_USE(setup_mocks, teardown_mocks))
$ {
    int ret = shell_run_from_env(environ);

    CR_ASSERT_EQ(ret, EXIT_OK);
}
