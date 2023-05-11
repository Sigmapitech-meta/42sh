/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias_resolver.c
*/

#include <string.h>
#include "list.h"

#include "shell/alias.h"
#include "shell/shell.h"
#include "utils/debug_mode.h"

bool_t is_alias(char *str)
{
    AUTOFREE char **words = NULL;
    AUTOFREE char *dup = strdup(str);

    if (!dup)
        return FALSE;
    words = str_split(dup, " =");
    return (
        words && words[1] && words[2]
        && !strcmp(words[0], "alias")
    );
}

static
alias_t *alias_get_from_key(aliases_t *aliases, char *name)
{
    alias_t *al;

    if (!aliases->pool || !name)
        return NULL;
    LIST_FOREACH(aliases->pool, node) {
        al = (alias_t *)node->value;
        if (!al || !al->key)
            return NULL;
        if (!strcmp(al->key, name))
            return al;
    }
    return NULL;
}

static
char **alias_expand(aliases_t *aliases, char **ptr, char *name)
{
    alias_t *al = alias_get_from_key(aliases, name);

    if (!al) {
        *ptr = name;
        return ++ptr;
    }
    DEBUG("Found alias [%s]", al->key);
    for (size_t i = 0; i < al->member_count; i++) {
        *ptr = al->members[i];
        ptr++;
    }
    return ptr;
}

static
int alias_resolve_size(aliases_t *aliases, command_t *cmd)
{
    alias_t *alias;
    int count = 0;

    if (!aliases)
        return cmd->argc;
    for (int i = 0; i < cmd->argc; i++) {
        alias = alias_get_from_key(aliases, cmd->argv[i]);
        count += (alias) ? alias->member_count : 1;
    }
    return count;
}

void alias_resolve(aliases_t *aliases, command_t *cmd)
{
    char **argv;
    char **argv_ptr;
    int count = alias_resolve_size(aliases, cmd);

    if (!aliases)
        return;
    argv = malloc((count + 1) * sizeof (char *));
    if (!argv)
        return;
    argv_ptr = argv;
    for (int i = 0; i < cmd->argc; i++)
        argv_ptr = alias_expand(aliases, argv_ptr, cmd->argv[i]);
    free(cmd->argv);
    cmd->argv = argv;
    cmd->argc = count;
    cmd->argv[cmd->argc] = NULL;
}
