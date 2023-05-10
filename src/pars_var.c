/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** pars_var.c
*/

#include <ctype.h>
#include <string.h>

#include "base.h"
#include "shell/shell.h"
#include "utils/cleanup.h"
#include "utils/debug_mode.h"
#include "utils/sentinel.h"

static
char *get_key(char *input)
{
    int i = 1;
    char *dup = strstr(input, "$");

    if (!dup)
        return NULL;
    dup = strdup(dup);
    if (!dup)
        return NULL;
    for (; dup[i] && isalnum(dup[i]); i++)
        ;
    dup[i] = '\0';
    return dup;
}

static
char *env_get_key(char *input)
{
    AUTOFREE char *dup = get_key(input);
    char *checkpoint;
    char *cpy;
    char *var_present = NULL;
    int i = 0;

    if (!dup)
        return NULL;
    do {
        cpy = strdup(environ[i]);
        if (!cpy)
            return NULL;
        cpy = strtok_r(cpy, "=", &checkpoint);
        var_present = strstr(dup, cpy);
        free(cpy);
        i++;
    } while (!var_present && environ[i]);
    return NULL_OR(var_present, strdup(var_present));
}

static
char *key_replace(context_t *ctx, char *from, char *value, char *input)
{
    AUTOFREE char *raw = strdup(input);
    char *out;

    if (!raw)
        return NULL;
    out = str_replace(raw, from, value);
    if (!out)
        return NULL;
    if (out == raw)
        return input;
    ctx->input_size = strlen(out);
    free(input);
    return out;
}

static
char *replace_a_var(context_t *ctx, char *input)
{
    AUTOFREE char *from = NULL;
    AUTOFREE char *key = env_get_key(input);
    char *value;

    if (!key)
        return input;
    value = getenv(key);
    if (!value)
        return NULL;
    from = malloc((1 + strlen(key) + 1) * sizeof(char));
    return NULL_OR(
        from && !IS_SENTINEL(snprintf(from, 1 + strlen(key) + 1, "$%s", key)),
        key_replace(ctx, from, value, input)
    );
}

char *replace_var(context_t *ctx, char *input)
{
    char *out = NULL;
    char *tmp = input;

    do {
        out = replace_a_var(ctx, tmp);
        tmp = out;
        if (!out)
            return NULL;
    } while (strstr(out, "$") && tmp != input);
    return out;
}
