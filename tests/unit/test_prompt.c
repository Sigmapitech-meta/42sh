/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_prompt.c
*/

#include "base.h"
#include "coding_style_fix.h"
#include "sputnik.h"
#include "shell/shell.h"
#include "shell/prompt.h"

#include "mocks/getcwd.h"
#include "mocks/getenv.h"
#include "mocks/gethostname.h"

void setup_mocks(void)
{
    redirect_all_std();
    break_getcwd();
    break_getenv();
    break_gethostname();
}

void teardown_mocks(void)
{
    fix_getcwd();
    fix_getenv();
    fix_gethostname();
}

TEST(
    prompt_display, should_print_the_prompt_format,
    TEST_USE(setup_mocks, teardown_mocks)
) $ {
    prompt_display();
    fflush(stdout);
    CR_ASSERT_STDOUT_EQ_STR(FORMAT_PROMPT);
}
