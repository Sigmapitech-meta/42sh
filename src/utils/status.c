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
        eprintf("Error Handling\n");
        return;
    }
    if (!WIFEXITED(status) && WIFSIGNALED(status)) {
        if (WTERMSIG(status) != FLOATING_EXCEPTION)
            eprintf("%s", strsignal(WTERMSIG(status)));
        else
            eprintf("Floating exception");
        if (WCOREDUMP(status))
            eprintf(" (core dumped)");
        eprintf("\n");
    }
}
