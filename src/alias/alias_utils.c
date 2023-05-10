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

static
void alias_print_value(alias_t *al)
{
    printf("%s\t", al->key);
    for (size_t i = 0; i < al->member_count; i++) {
        if (i)
            printf(" ");
        printf("%s", al->members[i]);
    }
    printf("\n");
}

void alias_list_print(aliases_t *aliases)
{
    list_t *pool = NULL_OR(aliases, aliases->pool);

    if (!pool)
        return;
    if (!pool->size) {
        printf("No aliases found.\n");
        return;
    }
    LIST_FOREACH(pool, node)
        alias_print_value(node->value);
}
