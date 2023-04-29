/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** segfault.c
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigsegv(int signum __attribute__((unused)))
{
    fprintf(stderr, "Segmentation fault\n");
    _exit(1);
}

int main(void)
{
    int *ptr = NULL;
    struct sigaction sa;

    sa.sa_handler = handle_sigsegv;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    sigaction(SIGSEGV, &sa, NULL);
    *ptr = 0;
    return 0;
}
