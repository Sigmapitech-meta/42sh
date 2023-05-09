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

static
bool_t alias_init(aliases_t *aliases)
{
    char **lines;

    aliases->config_file = file_read(".42shrc");
    if (!aliases->config_file)
        return FALSE;
    lines = str_split(aliases->config_file, "\n");
    for (int i = 0; lines[i]; i++) {
        if (!is_alias(lines[i]))
            continue;
        if (alias_add(aliases->pool, lines[i]))
            return FALSE;
    }
    aliases->lines = lines;
    return TRUE;
}

aliases_t *alias_list_create(void)
{
    aliases_t *aliases = malloc(sizeof (aliases));

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
    list_destroy(aliases->pool);
    free(aliases->config_file);
    free(aliases->lines);
}
