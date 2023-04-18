/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** environment.c
*/

#include <stddef.h>
#include <malloc.h>
#include "epitech/base.h"
#include "epitech/list.h"
#include "shell/environment.h"
#include "wololo/sentinel.h"

list_t *env_parse(char **env)
{
    list_t *env_lst = list_create();

    if (!env_lst)
        return NULL;
    for (int i = 0; env[i]; i++)
        if (!LIST_APPEND_CHECK(env_lst, str_duplicate(env[i])))
            list_destroy(env_lst);
    return env_lst;
}

char **env_rebuild(list_t *env)
{
    list_node_t *node = env->head;
    char **out = malloc((env->size + 1) * sizeof (char *));
    int i = 0;

    if (!out)
        return NULL;
    while (node) {
        out[i] = list_get(env, i);
        node = node->next;
        i++;
    }
    out[i] = NULL;
    return out;
}

int env_find(list_t *env, char *name, int n)
{
    int i = 0;
    list_node_t *node = env->head;

    while (node) {
        if (!str_compare(node->value, name, n))
            return i;
        node = node->next;
        i++;
    }
    return W_SENTINEL;
}
