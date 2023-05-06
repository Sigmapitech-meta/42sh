/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** segfault.c
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigfpe(int signum __attribute__((unused)))
{
    fprintf(stderr, "floating point exception\n");
    _exit(SIGFPE);
}

int main(void)
{
    int zero = 0;
    int one = 1;
    struct sigaction sa;

    sa.sa_handler = handle_sigfpe;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    sigaction(SIGFPE, &sa, NULL);
    one /= zero;
    return 0;
}
