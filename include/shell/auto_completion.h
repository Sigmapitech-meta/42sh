/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** auto_completion.h
*/

#ifndef AUTO_COMPLETION_H
    #define AUTO_COMPLETION_H

typedef struct list_s list_t;

list_t *my_get_bin_list(char *env);
int my_print_recommendations(list_t *bins, char *input);
char **my_get_alias(void);
char **my_get_path(char *paths);
void free_array(char **array);
char **my_str_split(char *str, char *seps);
#endif /* AUTO_COMPLETION_H */
