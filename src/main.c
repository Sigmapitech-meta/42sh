/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** main.c
*/

#include <string.h>

#include "base.h"
#include "epitech.h"

#include "shell/shell.h"
#include "utils/debug_mode.h"

int main(int argc, char **argv, char **env)
{
    DEBUG("Received %d arg(s)", argc);
    if (argc > 1 && !strncmp(argv[1], "-h", 2))
        return EXIT_OK_MSG("%s", USAGE);
    if (argc >= MAX_ARG_COUNT)
        return EXIT_KO_MSG("Too many arguments\n");
    DEBUG_MSG("Starting minishell");
    return shell_run_from_env(env);
}
