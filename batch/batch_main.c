/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** batch_main.c
*/

#include <stdio.h>
#include <string.h>

#include "base.h"
#include "batch.h"

#include "epitech.h"
#include "utils/cleanup.h"
#include "run_shell_command.h"

void batch_run(char *filepath)
{
    AUTOFREE char *content = file_read(filepath);
    char *start_line;

    if (!content)
        return;
    start_line = strstr(content, "\n");
    if (!start_line)
        return;
    run_shell_command(
        str_trans(++start_line, '\n', ';')
    );
}

int main(int argc, char **argv)
{
    if (argc == 1)
        return EXIT_OK_MSG("Missing filepath.\n");
    batch_run(argv[1]);
    return EXIT_OK;
}
