/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** mock_execve.c
*/

#include <stdlib.h>
#include "epitech.h"
#include "mocks/execve.h"

#include "utils/attributes.h"

int wrap_execve(char *path UNUSED, char **argv UNUSED, char **env UNUSED)
{
    exit(EXIT_OK);
}
