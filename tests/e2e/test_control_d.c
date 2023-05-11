/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_control_d.c
*/

#include "sputnik.h"
#include "run_shell_command.h"
#include "epitech.h"
#include "shell/shell.h"
#include "mocks/isatty.h"
#include "mocks/getline.h"

static
void setup_exit_tty(void)
{
    yes_is_atty();
    redirect_all_std();
    static char *input = NULL;

    GETLINE_DATA->table = &input;
    GETLINE_DATA->mode = TABLE;
}

static
void teardown_exit_tty(void)
{
    not_is_not_atty();
    GETLINE_DATA->mode = NORMAL;
}

TEST(run_command_exit, tty_mode, TEST_USE(setup_exit_tty, teardown_exit_tty))
$ {
    ssize_t state;
    char buff[1024] = { '\0' };
    file_t *fake_stdout = cr_get_redirected_stdout();
    context_t ctx = {
        .ran_from_tty = isatty(STDIN_FILENO),
        .input_size = SENTINEL_OF(size_t),
        .is_running = TRUE
    };

    shell_run_from_ctx(&ctx);
    CR_ASSERT_EQ(ctx.status, EXIT_OK);
    CR_ASSERT_EQ(ctx.is_running, FALSE);
    fflush(stdout);
    state = fread(buff, 1, 1023, fake_stdout);
    if (IS_SENTINEL_OF(state, ssize_t))
    CR_SKIP("Cannot read fake stdout");
    buff[state] = '\0';
    CR_ASSERT_STR_EQ(buff + strlen(buff) - 5, "exit\n");
}
