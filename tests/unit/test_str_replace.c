/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_str_replace.c
*/

#include "base.h"
#include "coding_style_fix.h"
#include "sputnik.h"
#include "utils/cleanup.h"

TEST(str_replace, replace_with_last_command)
$ {
    AUTO_FREE char *out = str_replace("sudo !!", "!!", "ls -alr");

    if (!out)
        return;
    CR_ASSERT_STR_EQ(out, "sudo ls -alr");
}

TEST(str_replace, substring_not_found)
$ {
    CR_ASSERT_STR_EQ(str_replace("sudo", "!!", "ls -alr"), "sudo");
}

TEST(str_replace, multiple_occurences)
$ {
    AUTO_FREE char *out = str_replace("!! | !!", "!!", "mysh");

    if (!out)
        return;
    CR_ASSERT_STR_EQ(out, "mysh | mysh");
}
