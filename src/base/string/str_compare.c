/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** str_compare.c
*/

int str_compare(char const *s1, char const *s2, int n)
{
    if (!*s1 || !*s2)
        return *s1 - *s2;
    for (int i = 0; (s1[i] || s2[i]) && i < n; i++)
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    return 0;
}
