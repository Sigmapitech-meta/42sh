/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias.h
*/

#ifndef ALIAS_H
    #define ALIAS_H

typedef _Bool bool_t;
typedef struct list_s list_t;

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
void alias_list_print(aliases_t *aliases);

#endif
