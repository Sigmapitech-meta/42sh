/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_simple_alias.c
*/

#include "epitech.h"
#include "sputnik.h"
#include "shell/shell.h"
#include "mocks/getline.h"

static
void setup_mocks(void)
{
    static char *input = (
        "alias kek echo;"
        "kek baguette\n"
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

TEST(run_command_alias, simple_alias, TEST_USE(setup_mocks, teardown_mocks))
$ {
    int ret = shell_run_from_env(environ);

    CR_ASSERT_STDOUT_EQ_STR("baguette\n");
    CR_ASSERT_EQ(ret, EXIT_OK);
}
