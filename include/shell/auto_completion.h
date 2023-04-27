/*
** EPITECH PROJECT, 2023
** auto_completion.h
** File description:
** auto_complet header
*/

#ifndef AUTO_H
    #define AUTO_H

typedef struct list_s list_t;

/* PROTOTYPES */
list_t my_get_bin_list(char *env);
int my_print_recommendations(list_t *bins, char *input);
char **my_get_alias(void);
/* PROTOTYPES */

#endif
