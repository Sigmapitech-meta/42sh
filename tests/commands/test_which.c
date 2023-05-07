/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_which_fail.c
*/

#include <unistd.h>
#include "sputnik.h"
#include "run_shell_command.h"
#include "utils/sentinel.h"

TEST_STD(run_command_which, no_argument)
$ {
    CR_ASSERT_EQ(run_shell_command("which"), 0);
    CR_ASSERT_STDERR_EQ_STR("which: Too few arguments.\n");
}

TEST_STD(run_command_which, simple_ls)
$ {
    char buff[1024] = { '\0' };
    FILE *fake_stdout = cr_get_redirected_stdout();
    int state;

    CR_ASSERT_EQ(run_shell_command("which ls"), 0);
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
    char buff[1024] = { '\0' };
    FILE *fake_stdout = cr_get_redirected_stdout();
    int state;

    CR_ASSERT_EQ(run_shell_command("which which"), 0);
    state = read(fake_stdout->_fileno, buff, 1023);
    if (IS_SENTINEL_OF(state, ssize_t))
        cr_skip("Cannot read fake stdout");
    buff[state] = '\0';
    CR_ASSERT(
        strncmp(buff + state - 4, "/ls\n", 2),
        "which: shell built-in command."
    );
}
