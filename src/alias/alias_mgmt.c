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
#include "utils/sentinel.h"
#include "utils/cleanup.h"

static
bool_t is_alias(char *str)
{
    AUTOFREE char **words = str_split(str, " =");

    return (
        words && words[1] && words[2]
        && !strcmp(words[0], "alias")
    );
}

list_t *alias_create_list(void)
{
    list_t *list = list_create();
    AUTOFREE char *file_content = file_read(".42shrc");
    AUTOFREE char **lines = NULL;

    if (!file_content)
        return NULL;
    lines = str_split(file_content, "\n");
    for (int i = 0; lines[i]; i++)
        if (is_alias(lines[i]))
            list_append(list, lines[i]);
    return list;
}

int alias_add(list_t *alias, char *input)
{
    return (
        is_alias(input)
        && !IS_SENTINEL(list_append(alias, input))
    );
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
