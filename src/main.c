/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** main.c
*/

#include <string.h>
#include <stdlib.h>

#include "base.h"
#include "epitech.h"

#include "shell/shell.h"
#include "utils/debug_mode.h"

int run_script_file(char *filepath, char **env)
{
    int ret;
    file_t *file = fopen(filepath, "r");
    size_t byte_read;
    char *line;

    if (!file)
        return EXIT_KO;
    set_getline_source(file);
    byte_read = get_line(&line);
    if (byte_read && line && !strncmp(line, "#!", 2)) {
        free(line);
        ret = shell_run_from_env(env);
        fclose(file);
    } else
        ret = EXIT_KO;
    return ret;
}

int main(int argc, char **argv, char **env)
{
    DEBUG("Received %d arg(s)", argc);
    if (argc > 1 && !strncmp(argv[1], "-h", 2))
        return EXIT_OK_MSG("%s", USAGE);
    if (argc > MAX_ARG_COUNT)
        return EXIT_KO_MSG("Too many arguments\n");
    if (argc == MAX_ARG_COUNT)
        return run_script_file(argv[1], env);
    DEBUG_MSG("Starting minishell");
    return shell_run_from_env(env);
}
