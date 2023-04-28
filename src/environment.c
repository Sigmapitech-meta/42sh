/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** environment.c
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "utils/sentinel.h"

list_t *env_parse(char **env)
{
    list_t *env_lst = list_create();

    if (!env_lst)
        return NULL;
    for (int i = 0; env[i]; i++)
        if (!LIST_APPEND_CHECK(env_lst, strdup(env[i])))
            list_destroy(env_lst);
    return env_lst;
}

char **env_rebuild(list_t *env)
{
    char **out = malloc((env->size + 1) * sizeof (char *));
    int i = 0;

    if (!out)
        return NULL;
    LIST_FOREACH(env, node) {
        out[i] = list_get(env, i);
        i++;
    }
    out[i] = NULL;
    return out;
}

int env_find(list_t *env, char *name, int n)
{
    int i = 0;

    LIST_FOREACH(env, node) {
        if (!strncmp(node->value, name, n))
            return i;
        i++;
    }
    return W_SENTINEL;
}
