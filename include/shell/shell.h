/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** shell.h
*/
#ifndef SHELL_H_
    #define SHELL_H_

    #define MAX_ARG_COUNT (2)
    #define IS_ARG_EQ(v) (argc > 1 && !STR_COMPARE_FIX(argv[1], v))

void shell_run_from_env(char **env);
#endif /* !SHELL_H_ */
