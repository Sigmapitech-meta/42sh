/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** main.c
*/

#include <string.h>

#include "epitech.h"

#include "shell/shell.h"
#include "utils/debug_mode.h"
#include "printf_expansion.h"

DEBUG_EXPR(void ncurses_init(void));

int main(int argc, char **argv, char **env)
{
    DEBUG_CALL(ncurses_init);
    DEBUG_EXPR(return 0);
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
