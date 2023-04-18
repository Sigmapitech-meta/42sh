/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** str_copy.c
*/

void str_copy(char *src, char *dest)
{
    int i = 0;

    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
}
