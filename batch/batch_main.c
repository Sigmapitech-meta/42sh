/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** batch_main.c
*/

#include <stdio.h>
#include <string.h>

#include "batch.h"

#include "epitech.h"
#include "utils/autofree.h"
#include "run_shell_command.h"

char *str_trans(char *string, char in, char out)
{
    for (int i = 0; string[i]; i++)
        if (string[i] == in)
            string[i] = out;
    return string;
}

void batch_run(char *filepath)
{
    AUTOFREE char *content = file_read(filepath);
    char *skip_first_line;

    if (!content)
        return;
    skip_first_line = strstr(content, "\n");
    if (!skip_first_line)
        return;
    run_shell_command(
        str_trans(++skip_first_line, '\n', ';')
    );
}

int main(int argc, char **argv)
{
    if (argc == 1)
        return EXIT_OK_MSG("Missing filepath.\n");
    batch_run(argv[1]);
    return EXIT_KO;
}
