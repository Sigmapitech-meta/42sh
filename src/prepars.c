/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** prepars.c
*/

#include <stdlib.h>
#include <string.h>

#include "shell/shell.h"
#include "base.h"
#include "utils/sentinel.h"
#include "utils/cleanup.h"
#include "utils/debug_mode.h"

static
char *replace_status(context_t *ctx, char *input)
{
    static char buff_status[7] = { 0 };
    char *out;
    AUTOFREE char *raw = strdup(input);

    if (!raw || IS_SENTINEL(snprintf(buff_status, 7, "%i", ctx->status)))
        return NULL;
    out = str_replace(raw, "$?", buff_status);
    if (!out)
        return NULL;
    if (out == raw)
        return input;
    ctx->input_size = strlen(out);
    free(input);
    return out;
}

static
char *replace_pid(context_t *ctx)
{
    static char buff_pid[12] = { 0 };
    char *out;
    AUTOFREE char *raw = strdup(ctx->user_input);

    if (!buff_pid[0] && IS_SENTINEL(snprintf(buff_pid, 12, "%i", getpid())))
        return NULL;
    if (!raw)
        return NULL;
    out = str_replace(raw, "$$", buff_pid);
    if (!out)
        return NULL;
    if (out == raw)
        return ctx->user_input;
    ctx->input_size = strlen(out);
    free(ctx->user_input);
    return out;
}

char *prepars(context_t *ctx)
{
    char *out1 = replace_pid(ctx);
    char *out2 = replace_status(ctx, out1);
    char *out3 = replace_var(ctx, out2);

    return out3;
}