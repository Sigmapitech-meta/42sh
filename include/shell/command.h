/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** command.h
*/
#ifndef COMMAND_H_
    #define COMMAND_H_

typedef enum bool_s bool_t;
typedef struct context_s context_t;

typedef struct command_s {
    int argc;
    char **argv;
} command_t;

bool_t command_run_subprocess(context_t *ctx);
#endif /*COMMAND_H_*/
