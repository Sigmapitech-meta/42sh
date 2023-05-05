/*
** EPITECH PROJECT, 2023
** minishell_2
** File description:
** main.c
*/

#include <string.h>

#include "epitech.h"

#include "shell/alias.h"
#include "shell/shell.h"
#include "shell/auto_completion.h"
#include "utils/debug_mode.h"
#include "printf_expansion.h"

int main(int argc, char **argv, char **env)
{
    DEBUG("Received %d arg(s)", argc);
    if (argc > 1 && !strncmp(argv[1], "-h", 2)) {
        printf("%s", USAGE);
        return EXIT_OK;
    }
    if (argc >= MAX_ARG_COUNT) {
        eprintf("Too many arguments\n");
        return EXIT_OK;
    }
    DEBUG_MSG("Starting minishell");
    return shell_run_from_env(env);
}
