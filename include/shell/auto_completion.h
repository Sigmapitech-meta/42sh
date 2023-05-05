/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** auto_completion.h
*/

#ifndef AUTO_COMPLETION_H
    #define AUTO_COMPLETION_H
    #include <stdbool.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <string.h>
    #include "list.h"

list_t *my_get_bin_list(char *env);
char *my_print_recommendations(list_t *bins, char *input);
char **my_get_alias(void);
char **my_get_path(char *paths);
char **my_str_split(char *str, char *seps);
char *my_strcat(char *src1, char *src2);
void print_coms(list_t *bins);
char *my_switch_coms(list_t *bins, char *input);
#endif /* AUTO_COMPLETION_H */
