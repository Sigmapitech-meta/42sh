/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** execve.h
*/

#ifndef MOCK_EXECVE_H_
    #define MOCK_EXECVE_H_

    #define real_execve __real_execve
    #define wrap_execve __wrap_execve

int wrap_execve(char *path, char **argv, char **env);
int real_execve(char *path, char **argv, char **env);

#endif /* !MOCK_EXECVE_H_ */
