/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** mock_execve.c
*/

#include "epitech.h"
#include "mocks/execve.h"

#include "utils/attributes.h"

int wrap_execve(char *path UNUSED, char **argv UNUSED, char **env UNUSED)
{
    return EXIT_OK;
}
