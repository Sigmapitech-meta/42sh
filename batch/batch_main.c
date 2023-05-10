/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** batch_main.c
*/

#include <stdio.h>
#include <string.h>

#include "base.h"
#include "epitech.h"
#include "run_shell_command.h"

#include "shell/shell.h"
#include "utils/cleanup.h"

context_t *batch_run(char *filepath)
{
    AUTOFREE char *content = file_read(filepath);
    char *start_line;

    if (!content)
        return NULL;
    start_line = strstr(content, "\n");
    if (!start_line)
        return NULL;
    return run_shell_command(
        str_trans(++start_line, '\n', ';')
    );
}

int main(int argc, char **argv)
{
    int ret;
    context_t *ctx;

    if (argc == 1)
        return EXIT_OK_MSG("Missing filepath.\n");
    ctx = batch_run(argv[1]);
    if (!ctx)
        return EXIT_OK;
    ret = ctx->status;
    context_destroy(ctx);
    return ret;
}
