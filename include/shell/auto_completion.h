/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** auto_completion.h
*/

#ifndef AUTO_COMPLETION_H
    #define AUTO_COMPLETION_H

typedef struct list_s list_t;

/* PROTOTYPES */
list_t my_get_bin_list(char *env);
int my_print_recommendations(list_t *bins, char *input);
char **my_get_alias(void);
/* PROTOTYPES */

#endif
