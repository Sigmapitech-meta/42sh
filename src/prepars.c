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
#include "shell/history.h"

char *pre_parse_replace(context_t *ctx, char *from, char *to, char *input)
{
    AUTO_FREE char *raw = strdup(input);
    char *out = NULL_OR(raw, str_replace(raw, from, to));

    if (!out)
        return NULL;
    if (out == raw)
        return input;
    ctx->input_size = strlen(out);
    free(input);
    return out;
}

static
char *replace_status(context_t *ctx, char *input)
{
    char status[MAX_SHORT_LENGTH] = { '\0' };
    int pid_size = snprintf(status, MAX_SHORT_LENGTH, "%i", ctx->status);

    return NULL_OR(
        !IS_SENTINEL(pid_size),
        pre_parse_replace(ctx, "$?", status, input)
    );
}

static
char *replace_pid(context_t *ctx, char *input)
{
    static char pid[MAX_INT_LEN] = { '\0' };
    static int pid_size = SENTINEL;

    if (IS_SENTINEL(pid_size))
        pid_size = snprintf(pid, MAX_INT_LEN, "%i", getpid());
    return NULL_OR(
        !IS_SENTINEL(pid_size),
        pre_parse_replace(ctx, "$$", pid, input)
    );
}

static
char *replace_bang(context_t *ctx)
{
    char *last_cmd;

    if (ctx->history && ctx->history->pool && ctx->history->pool->tail)
        last_cmd = ctx->history->pool->tail->value;
    else
        last_cmd = ctx->user_input;
    return pre_parse_replace(ctx, "!!", last_cmd, ctx->user_input);
}

char *prepars(context_t *ctx)
{
    DEBUG_USED list_t *pool = ctx->history ? ctx->history->pool : NULL;
    char *out = replace_bang(ctx);

    if (!out)
        return NULL;
    if (ctx->history) {
        history_append(ctx->history, strdup(out));
        DEBUG("hist size [%d], last cmd [%s]", pool->size, pool->tail->value);
    }
    out = replace_pid(ctx, out);
    if (!out)
        return NULL;
    out = replace_status(ctx, out);
    DEBUG("replace before var: %s", out);
    if (!out)
        return NULL;
    out = replace_var(ctx, out);
    DEBUG("replace after all: %s", out);
    return out;
}
