/*
** EPITECH PROJECT, 2023
** minishell_2
** File description:
** main.c
*/

#include <string.h>
#include <unistd.h>

#include "epitech.h"

#include "shell/shell.h"
#include "wololo/debug_mode.h"
#include "wololo/write.h"

int main(int argc, char **argv, char **env)
{
    DEBUG("Received %d arg(s)", argc);
    if (argc > 1 && !strncmp(argv[1], "-h", 2))
        return EXIT_OK_MSG(USAGE);
    if (argc >= MAX_ARG_COUNT)
        return EXIT_KO_MSG("Too many arguments\n");
    DEBUG_MSG("Starting minishell");
    shell_run_from_env(env);
    return EXIT_OK;
}
