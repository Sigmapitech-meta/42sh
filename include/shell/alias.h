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

char *my_strcat(char *left, char *right);
char **my_str_split(char *str, char *seps);
bool_t is_alias(char *str);
list_t *create_list_alias(void);
int add_alias(list_t *alias, char *input);
void alias_command(list_t *alias);
char *replace_alias_with_command(list_t *alias, char *input);
#endif
