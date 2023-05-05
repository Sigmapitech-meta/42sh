/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_get_line_broken.c
*/

#include "base.h"
#include "epitech.h"
#include "epitech/sputnik.h"
#include "mocks/getline.h"
#include "shell/shell.h"

TEST_STD(get_line, getline_broken)
$ {
    context_t ctx = { .is_running = TRUE };

    setbuf(stdout, 0);
    GETLINE_DATA->mode = BROKEN;
    CR_ASSERT_NOT(shell_read_line(&ctx));
    CR_ASSERT_NOT(ctx.is_running);
    GETLINE_DATA->mode = NORMAL;
    CR_ASSERT_STDOUT_EQ_STR("");
}

TEST(get_line, getline_broken_command)
$ {
    context_t ctx = {
        .ran_from_tty = FALSE,
        .is_running = TRUE
    };

    GETLINE_DATA->mode = BROKEN;
    shell_run_from_ctx(&ctx);
    CR_ASSERT_EQ(ctx.status, EXIT_FAILURE);
    GETLINE_DATA->mode = NORMAL;
}
