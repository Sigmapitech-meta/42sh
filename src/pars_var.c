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

    dup = NULL_OR(dup, strdup(dup));
    if (!dup)
        return NULL;
    while (dup[i] && isalnum(dup[i]))
        i++;
    dup[i] = '\0';
    return dup;
}

static
char *env_get_key(char *input)
{
    AUTO_FREE char *dup = get_key(input);
    char *checkpoint;
    char *copy;
    char *var_present = NULL;
    int i = 0;

    if (!dup)
        return NULL;
    do {
        copy = strdup(environ[i]);
        if (!copy)
            return NULL;
        copy = strtok_r(copy, "=", &checkpoint);
        var_present = strstr(dup, copy);
        free(copy);
        i++;
    } while (!var_present && environ[i]);
    return NULL_OR(var_present, strdup(var_present));
}

static
char *replace_a_var(context_t *ctx, char *input)
{
    AUTO_FREE char *from = NULL;
    AUTO_FREE char *key = env_get_key(input);
    char *value;
    size_t len;

    if (!key)
        return input;
    value = getenv(key);
    if (!value)
        return NULL;
    len = (1 + strlen(key) + 1);
    from = malloc(len * sizeof(char));
    return NULL_OR(
        from && !IS_SENTINEL(snprintf(from, len, "$%s", key)),
        pre_parse_replace(ctx, from, value, input)
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
