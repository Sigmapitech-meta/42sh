/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** str_len.c
*/

#include <stddef.h>

__attribute__((optimize(0)))
size_t str_len(char *src) {
    size_t size = 0;

    if (!src)
        return 0;
    while (src[size])
        size++;
    return size;
}
