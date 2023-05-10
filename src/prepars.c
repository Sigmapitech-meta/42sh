/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** prepars.c
*/

#include <stdlib.h>
#include <string.h>

#include "base.h"
#include "shell/shell.h"
#include "utils/cleanup.h"
#include "utils/debug_mode.h"
#include "utils/sentinel.h"

#define MAX_SHORT_LENGTH 6
#define MAX_INT_LENGTH 12

static
char *replace_status(context_t *ctx, char *input)
{
    static char status[MAX_SHORT_LENGTH] = { '\0' };
    AUTOFREE char *raw = strdup(input);
    char *out;

    if (!raw
        || IS_SENTINEL(snprintf(status, MAX_SHORT_LENGTH, "%i", ctx->status))
        )
        return NULL;
    out = str_replace(raw, "$?", status);
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
    static char buff_pid[MAX_INT_LENGTH] = { '\0' };
    AUTOFREE char *raw = strdup(ctx->user_input);
    char *out;

    if (!buff_pid[0]
        && IS_SENTINEL(snprintf(buff_pid, MAX_INT_LENGTH, "%i", getpid()))
        )
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
    char *out = replace_pid(ctx);

    if (!out) {
        ctx->input_size = SENTINEL;
        return NULL;
    }
    out = replace_status(ctx, out);
    DEBUG("%s", out);
    if (!out) {
        ctx->input_size = SENTINEL;
        return NULL;
    }
    out = replace_var(ctx, out);
    DEBUG("%s", out);
    if (!out)
        ctx->input_size = SENTINEL;
    return out;
}