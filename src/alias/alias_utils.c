/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias_utils.c
*/

#include <stdio.h>
#include <string.h>

#include "base.h"

#include "list.h"
#include "shell/alias.h"
#include "utils/cleanup.h"
#include "shell/shell.h"
#include "utils/debug_mode.h"
#include "epitech.h"

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

void alias_list_print(aliases_t *aliases)
{
    alias_t *al;
    list_t *pool;

    if (!aliases)
        return;
    pool = aliases->pool;
    if (!pool)
        return;
    if (!pool->size) {
        printf("No aliases found.\n");
        return;
    }
    LIST_FOREACH(aliases->pool, node) {
        al = (alias_t *)(node->value);
        printf("%s\t", al->key);
        for (size_t i = 0; i < al->member_count; i++)
            printf(" %s", al->members[i]);
        printf("\n");
    }
}
