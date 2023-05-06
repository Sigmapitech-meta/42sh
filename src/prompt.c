/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** prompt.c
*/

#include <stdio.h>
#include <unistd.h>

#include "shell/prompt.h"
#include "shell/shell.h"
#include "utils/cleanup.h"

void prompt_display(void)
{
    AUTOFREE char *current_dir = getcwd(NULL, 0);
    char hostname[HOSTNAME_MAX_LEN];
    char *username = getenv("USER");

    hostname[HOSTNAME_MAX_LEN - 1] = '\0';
    gethostname(hostname, HOSTNAME_MAX_LEN - 1);
    printf(FORMAT_PROMPT, username, hostname, current_dir);
}
