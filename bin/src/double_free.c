/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** double_free.c
*/

#include <stdlib.h>

int main(void)
{
    void *ptr = malloc(1);

    free(ptr);
    free(ptr);
}
