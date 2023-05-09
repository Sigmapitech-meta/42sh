/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias_mgmt.c
*/

#include <string.h>

#include "base.h"
#include "epitech.h"
#include "list.h"

#include "shell/alias.h"
#include "utils/sentinel.h"

static
bool_t alias_fill(alias_t *alias, char *str, int count)
{
    char **words;

    alias->raw = strdup(str);
    if (!alias->raw) {
        return FALSE;
    }
    words = str_split(alias->raw, " =");
    if (!words) {
        free(alias->raw);
        return FALSE;
    }
    alias->key = words[1];
    alias->members = words + 2;
    alias->member_count = count - 2;
    return TRUE;
}

bool_t alias_add(aliases_t *aliases, char *str)
{
    alias_t *alias;
    int count;

    if (!aliases || !is_alias(str))
        return FALSE;
    count = str_count_tok(str, " =");
    alias = malloc(sizeof (*alias));
    if (!alias)
        return FALSE;
    if (!alias_fill(alias, str, count)) {
        free(alias);
        return FALSE;
    }
    return !IS_SENTINEL(list_append(aliases->pool, alias));
}
