/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** std_redirect.c
*/

#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
