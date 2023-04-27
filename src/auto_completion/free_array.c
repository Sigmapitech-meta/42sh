/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** free_array.c
*/

#include <stdlib.h>
#include "shell/auto_completion.h"

void free_array(char **array)
{
    for (int i = 0; array[i]; i ++)
        free(array[i]);
    free(array);
}
