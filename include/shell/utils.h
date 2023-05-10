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

/** @brief Concatenate two paths */
char *path_concat(char *left, char *right);

/** @brief Retrieve the path of a command */
char *path_find_cmd(char *cmd);

/** @brief Retrieve the command path if it can be accessed */
char *path_find_access(char *path, char *cmd);

/** @brief Print the status message for a given code */
void status_show(int status);

/** @brief set a environment variable and handle necessary cleanups */
void putenv_safe(char *key, char *value, char **original_env);

#endif /* !UTILS_H_ */
