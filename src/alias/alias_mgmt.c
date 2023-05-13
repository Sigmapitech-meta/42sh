/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias_mgmt.c
*/

#include <string.h>

#include "base.h"
#include "list.h"

#include "shell/alias.h"
#include "utils/debug_mode.h"
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

static
bool_t alias_init(aliases_t *aliases)
{
    int count_lines;

    aliases->config_file = file_read(".42shrc");
    if (!aliases->config_file)
        return TRUE;
    count_lines = str_count_tok(aliases->config_file, "\n");
    aliases->lines = str_split(aliases->config_file, "\n");
    for (int i = 0; i < count_lines; i++) {
        DEBUG("reading: [%s]", aliases->lines[i]);
        if (!is_alias(aliases->lines[i]))
            continue;
        if (!alias_add(aliases, aliases->lines[i]))
            return FALSE;
    }
    return TRUE;
}

aliases_t *alias_list_create(void)
{
    aliases_t *aliases = malloc(sizeof (*aliases));

    if (!aliases)
        return NULL;
    aliases->pool = list_create();
    if (!aliases->pool) {
        free(aliases);
        return NULL;
    }
    aliases->lines = NULL;
    if (!alias_init(aliases)) {
        free(aliases);
        return NULL;
    }
    return aliases;
}

void alias_list_destroy(aliases_t *aliases)
{
    alias_t *al;

    LIST_FOREACH(aliases->pool, node) {
        al = (alias_t *)(node->value);
        if (al) {
            free(al->raw);
            free(al->members - 2);
            free(al);
        }
    }
    list_destroy(aliases->pool);
    free(aliases->config_file);
    if (aliases->lines)
        free(aliases->lines);
    free(aliases);
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
