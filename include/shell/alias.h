/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias.h
*/

#ifndef ALIAS_H
    #define ALIAS_H

    #include "list.h"

typedef _Bool bool_t;

typedef struct command_s command_t;
typedef struct context_s context_t;

    #define STATIC_LEN(str) (sizeof (str) - 1)

static const int ALIAS_FMT_SIZE = STATIC_LEN("alias =");

typedef struct aliases_s {
    char *config_file;
    char **lines;
    list_t *pool;
} aliases_t;

typedef struct {
    char *key;
    size_t member_count;
    char **members;
    char *raw;
} alias_t;

aliases_t *alias_list_create(void);
void alias_list_destroy(aliases_t *aliases);

bool_t alias_add(aliases_t *aliases, char *input);
bool_t is_alias(char *str);

void alias_resolve(aliases_t *aliases, command_t *cmd);

static inline
USED void alias_print_value(alias_t *al)
{
    printf("%s\t", al->key);
    for (size_t i = 0; i < al->member_count; i++) {
        if (i)
            printf(" ");
        printf("%s", al->members[i]);
    }
    printf("\n");
}

static inline
USED void alias_list_print(aliases_t *aliases)
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


#endif
