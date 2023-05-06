/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** environment.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "epitech.h"
#include "shell/shell.h"
#include "utils/debug_mode.h"
#include "utils/cleanup.h"

char *env_get_setter(char *key, char *value)
{
    int size = (int)strlen(key) + 2;
    char *setter;
    int written;

    if (value)
        size += (int)strlen(value);
    setter = malloc(size * sizeof (char));
    if (!setter)
        return NULL;
    written = snprintf(setter, size, "%s=", key);
    if (value)
        written += snprintf(setter + written, size - written, "%s", value);
    if (++written != size) {
        free(setter);
        return NULL;
    }
    return setter;
}

void env_free(char **original_env)
{
    bool_t is_present;

    for (int i = 0; environ[i]; i++) {
        is_present = FALSE;
        for (int j = 0; original_env[j] && !is_present; j++)
            is_present = !strcmp(environ[i], original_env[j]);
        if (!is_present) {
            DEBUG("Freeing [%s]", environ[i]);
            free(environ[i]);
        }
    }
}

USED
void env_free_key(char *key, char **original_env)
{
    char *transaction_ptr;
    AUTOFREE char *line_start = env_get_setter(key, NULL);
    size_t size;
    int i = 0;

    if (!line_start)
        return;
    size = strlen(line_start);
    for (; environ[i] && (bool_t)strncmp(environ[i], line_start, size); i++)
        ;
    if (environ[i] != original_env[i]) {
        transaction_ptr = environ[i];
        DEBUG("Freeing [%s]", transaction_ptr);
        unsetenv(key);
        free(transaction_ptr);
    }
}
