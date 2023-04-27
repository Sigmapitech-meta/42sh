/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** get_line.c
*/

#include <stdio.h>

size_t get_line(char **line)
{
    static size_t zero = 0;

    return getline(line, &zero, stdin);
}
