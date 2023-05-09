/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** builtin_alias.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "shell/alias.h"
#include "shell/shell.h"
#include "utils/sentinel.h"
#include "utils/cleanup.h"

char *alias_translate(context_t *ctx)
{
    command_t *cmd = ctx->cmd;
    size_t len = strlen(ctx->user_input);
    char *out = malloc((len + 1) * sizeof (char));
    char *offset = strstr(ctx->user_input, cmd->argv[2]);
    int written;

    if (!out)
        return NULL;
    written = snprintf(out, len + 1, "alias %s=%s", cmd->argv[1], offset);
    if (!IS_SENTINEL(written))
        return out;
    free(out);
    return NULL;
}

void builtin_alias(context_t *ctx)
{
    AUTOFREE char *out = NULL;
    command_t *cmd = ctx->cmd;

    if (cmd->argc == 1)
        return alias_list_print(ctx->aliases);
    if (cmd->argc == 2)
        return;
    out = alias_translate(ctx);
    if (!out || !alias_add(ctx->aliases, out))
        ctx->status = EXIT_FAILURE;
}
