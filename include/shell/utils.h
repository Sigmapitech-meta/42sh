/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** utils.h
*/

#ifndef UTILS_H_
    #define UTILS_H_

    #define FLOATING_EXCEPTION (8)

size_t get_line(char **line);

char *path_concat(char *left, char *right);
char *path_find_cmd(char *cmd);
char *path_find_access(char *path, char *cmd);

int param_count(const char *line);
void param_fill(char **params, char *string);

void status_show(int status);

#endif /* !UTILS_H_ */
