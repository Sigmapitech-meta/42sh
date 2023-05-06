/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_autoclose.c
*/

#include <fcntl.h>

#include "sputnik.h"
#include "mocks/getline.h"
#include "utils/cleanup.h"
#include "utils/sentinel.h"

static
void is_fd_sentinel(int fd)
{
    setbuf(stdout, 0);
    printf("%s", IS_SENTINEL(fd) ? "yes" : "no");
}

TEST_STD(autoclose, opened)
$ {
    AUTOCLOSE int fd = open("/dev/zero", O_RDONLY);

    if (!fd)
        return;
    is_fd_sentinel(fd);
    CR_ASSERT_STDOUT_EQ_STR("no");
}

TEST_STD(autoclose, null)
$ {
    AUTOCLOSE int fd = SENTINEL;

    is_fd_sentinel(fd);
    CR_ASSERT_STDOUT_EQ_STR("yes");
}
