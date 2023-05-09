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

    if (!aliases)
        return FALSE;
    words = str_split(str, " =");
    if (!words || !words[1] || !words[2])
        return FALSE;
    DEBUG("-> %s", words[0]);
    if (strcmp(words[0], "alias")) {
        free(words);
        return FALSE;
    }
    alias = malloc(sizeof (*alias));
    if (!alias)
        return FALSE;
    DEBUG("Register alias %s", str);
    alias->key = str;
    alias->members = words;
    alias->member_count = str_count_tok(str, " =");
    return !IS_SENTINEL(list_append(aliases->pool, str));
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
