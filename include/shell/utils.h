/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** utils.h
*/

#ifndef UTILS_H_
    #define UTILS_H_

enum {
    FLOATING_EXCEPTION = 8,
    SENTINEL_DETECT = 65280,
    SEGFAULT = 11,
    _CORE_DUMP = 128,
    SEGFAULT_CORE_DUMP = SEGFAULT | _CORE_DUMP
};

char *path_concat(char *left, char *right);
char *path_find_cmd(char *cmd);
char *path_find_access(char *path, char *cmd);

int param_count(const char *line);
void param_fill(char **params, char *string);

void status_show(int status);

void putenv_safe(char *key, char *value, char **original_env);

#endif /* !UTILS_H_ */
