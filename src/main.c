/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** main.c
*/

#include <stdlib.h>
#include <string.h>

#include "epitech.h"

#include "shell/shell.h"
#include "utils/debug_mode.h"
#include "printf_expansion.h"

static
void free_env(char **original_env)
{
    bool_t is_present;

    for (int i = 0; environ[i]; i++) {
        is_present = FALSE;
        for (int j = 0; original_env[j] && !is_present; j++)
            is_present = !strcmp(environ[i], original_env[j]);
        if (!is_present) {
            DEBUG("Freeing [%s] at index [%d]", environ[i], i);
            free(environ[i]);
        }
    }
}

int main(int argc, char **argv, char **env)
{
    int ret;

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
    ret = shell_run();
    free_env(env);
    return ret;
}
