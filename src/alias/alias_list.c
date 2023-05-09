/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias_list.c
*/

#include <string.h>

#include "base.h"
#include "epitech.h"
#include "list.h"

#include "shell/alias.h"
#include "utils/debug_mode.h"

static
bool_t alias_init(aliases_t *aliases)
{
    int count_lines;

    aliases->config_file = file_read(".42shrc");
    if (!aliases->config_file)
        return FALSE;
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
    free(aliases->lines);
    free(aliases);
}
