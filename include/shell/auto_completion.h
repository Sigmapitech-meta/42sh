/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** auto_completion.h
*/

#ifndef AUTO_COMPLETION_H
    #define AUTO_COMPLETION_H

typedef _Bool bool_t;
typedef struct list_s list_t;

list_t *my_get_bin_list(char *env);
char *my_print_recommendations(list_t *bins, char *input);
char **my_get_alias(void);
char **my_get_path(char *paths);
char **my_str_split(char *str, char *seps);
char *my_strcat(char *left, char *right);
void print_coms(list_t *bins);
char *my_switch_coms(list_t *bins, char *input);

#endif /* AUTO_COMPLETION_H */
