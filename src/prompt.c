/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** prompt.c
*/

#include <stdio.h>
#include <unistd.h>

#include "list.h"
#include "shell/prompt.h"
#include "shell/shell.h"
#include "utils/sentinel.h"
#include "utils/autofree.h"

void prompt_display(context_t *ctx)
{
    AUTOFREE char *current_dir = getcwd(NULL, 0);
    int user_node_id = ENV_FIND_VAR(ctx->env, "USER");
    char hostname[HOSTNAME_MAX_LEN];
    char *username = NULL;

    if (user_node_id != W_SENTINEL)
        username = list_get(ctx->env, user_node_id) + 5;
    hostname[HOSTNAME_MAX_LEN - 1] = '\0';
    gethostname(hostname, HOSTNAME_MAX_LEN - 1);
    printf(FORMAT_PROMPT, username, hostname, current_dir);
}
