/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** status.c
*/

#include <string.h>
#include <sys/wait.h>

#include "base.h"
#include "epitech.h"
#include "shell/utils.h"

void status_show(int status)
{
    if (status == EXIT_KO) {
        EPRINTF("Error Handling\n");
        return;
    }
    if (!WIFEXITED(status) && WIFSIGNALED(status)) {
        if (WTERMSIG(status) != FLOATING_EXCEPTION)
            EPRINTF("%s", strsignal(WTERMSIG(status)));
        else
            EPRINTF("Floating exception");
        if (WCOREDUMP(status))
            EPRINTF(" (core dumped)");
        EPRINTF("\n");
    }
}
