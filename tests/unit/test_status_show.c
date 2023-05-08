/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_prompt.c
*/

#include "base.h"
#include "coding_style_fix.h"
#include "sputnik.h"
#include "shell/utils.h"
#include "epitech.h"

TEST_STD(status_show, exit_ko)
$ {
    status_show(EXIT_KO);
    CR_ASSERT_STDERR_EQ_STR("Error Handling\n");
}

TEST_STD(status_show, segfault)
$ {
    status_show(SEGFAULT);
    CR_ASSERT_STDERR_EQ_STR("Segmentation fault\n");
}


TEST_STD(status_show, segfault_core_dump)
$ {
    status_show(SEGFAULT_CORE_DUMP);
    CR_ASSERT_STDERR_EQ_STR("Segmentation fault (core dumped)\n");
}

TEST_STD(status_show, fpe)
$ {
    status_show(FLOATING_EXCEPTION | _CORE_DUMP);
    CR_ASSERT_STDERR_EQ_STR("Floating exception (core dumped)\n");
}

TEST_STD(status_show, fpe_core_dump)
$ {
    status_show(FLOATING_EXCEPTION);
    CR_ASSERT_STDERR_EQ_STR("Floating exception\n");
}
