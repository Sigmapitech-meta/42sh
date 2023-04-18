/*
** EPITECH PROJECT, 2023
** Minishell
** File description:
** base header
*/

#ifndef E_BASE_H_
    #define E_BASE_H_

    #define STR_COMPARE_FIX(s1, s2) (str_compare(s1, s2, sizeof (s2) - 1))

typedef unsigned long size_t;

size_t get_line(char **line);

char *str_duplicate(char *src);
int str_compare(char const *s1, char const *s2, int n);
size_t str_len(char *src);
void str_copy(char *src, char *dest);

#endif /* !E_BASE_H_ */
