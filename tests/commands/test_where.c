/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_where_fail.c
*/

#include <unistd.h>
#include "sputnik.h"
#include "run_shell_command.h"
#include "utils/sentinel.h"
#include "epitech.h"

TEST_STD(run_command_where, no_arguments)
$ {
    CR_ASSERT_EQ(run_shell_command("where"), 1);
    CR_ASSERT_STDERR_EQ_STR("where: Too few arguments.\n");
}

TEST_STD(run_command_where, ls)
$ {
    char *buff;
    FILE *fake_stdout = cr_get_redirected_stdout();
    size_t track = 0;
    int count = 0;
    int read;

    CR_ASSERT_EQ(run_shell_command("which ls"), 0);
    do {
        read = getline(&buff, &track, fake_stdout);
        if (IS_SENTINEL_OF(read, ssize_t))
            break;
        CR_ASSERT(
            strncmp(buff + read - 4, "/ls\n", 2),
            "Should end with `.../ls\n`."
        );
    } while (++count);
    if (!count)
        cr_skip("Cannot read fake stdout");
}
