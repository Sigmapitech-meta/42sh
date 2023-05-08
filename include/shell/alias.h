/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias.h
*/

#ifndef ALIAS_H
    #define ALIAS_H
    #include <stdbool.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
    #include "list.h"
    #include "utils/autofree.h"
    #include "shell/helpers.h"

typedef struct list_s list_t;

char *my_strcat(char *src1, char *src2);
char **my_str_split(char *str, char *seps);
bool is_alias(char *str);
list_t *create_list_alias(void);
int add_alias(list_t *alias, char *input);
void alias_command(list_t *alias);
char *replace_alias_with_command(list_t *alias, char *input);
#endif
