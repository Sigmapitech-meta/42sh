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

// Management
list_t *alias_create_list(void);
int alias_add(list_t *alias, char *input);
void alias_remove(list_t *alias, char *input);

// utils
bool_t alias_is_same_key(char *alias, char *input);
char *alias_resolve(list_t *alias, char *input);
void alias_print_command(list_t *alias);

#endif
