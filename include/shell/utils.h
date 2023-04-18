/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** utils.h
*/

#ifndef UTILS_H_
    #define UTILS_H_

char *path_concat(char *left, char *right);
char *path_find_cmd(list_t *env, char *cmd);

int param_count(const char *line);
void param_fill(char **params, char *string);

#endif /* !UTILS_H_ */
