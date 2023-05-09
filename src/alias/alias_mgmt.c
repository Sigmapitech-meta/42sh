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
#include "utils/debug_mode.h"

bool_t alias_add(aliases_t *aliases, char *str)
{
    alias_t *alias;
    char **words;
    int count;

    if (!aliases || !is_alias(str))
        return FALSE;
    count = str_count_tok(str, " =");
    alias = malloc(sizeof (*alias));
    if (!alias)
        return FALSE;
    words = str_split(str, " =");
    if (!words) {
        free(alias);
        return NULL;
    }
    alias->raw = str;
    alias->key = words[1];
    alias->members = words + 2;
    alias->member_count = count - 2;
    return !IS_SENTINEL(list_append(aliases->pool, alias));
}

void alias_remove(list_t *alias, char *input)
{
    LIST_FOREACH(alias, node) {
        if (alias_is_same_key(node->value, input)) {
            list_remove_node(alias, node);
            break;
        }
    }
}
