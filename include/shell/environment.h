/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** environment.h
*/
#ifndef ENVIRONMENT_H_
    #define ENVIRONMENT_H_

    #define ENV_FIND_FIXED(env, name) env_find(env, name, sizeof(name) - 1)
    #define ENV_FIND_VAR(env, name) (ENV_FIND_FIXED(env, name "="))

list_t *env_parse(char **env);
char **env_rebuild(list_t *env);
int env_find(list_t *env, char *name, int n);
#endif /* !ENVIRONMENT_H_ */
