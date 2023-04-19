/*
** EPITECH PROJECT, 2023
** minishell_1
** File description:
** status.c
*/

#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#include "epitech.h"
#include "shell/utils.h"
#include "wololo/write.h"

void status_show(int status)
{
    if (status == EXIT_KO) {
        W_ERROR_LINE_C("Error Handling");
        return;
    }
    if (!WIFEXITED(status) && WIFSIGNALED(status)) {
        if (WTERMSIG(status) != FLOATING_EXCEPTION)
            dprintf(STDERR_FILENO, "%s", strsignal(WTERMSIG(status)));
        else
            W_ERROR_C("Floating exception");
        if (WCOREDUMP(status))
            W_ERROR_C(" (core dumped)");
        W_ERROR_C("\n");
    }
}
