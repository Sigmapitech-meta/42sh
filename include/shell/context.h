/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** context.h
*/

#ifndef CONTEXT_H_
    #define CONTEXT_H_

    #include "epitech/bool.h"
    #include "epitech/list.h"

typedef unsigned long size_t;
typedef struct command_s command_t;

typedef struct context_s {
    bool_t is_running;
    bool_t ran_from_tty;
    list_t *env;
    char *user_input;
    char *prev_dir;
    size_t input_size;
    command_t *cmd;
} context_t;

bool_t builtins_check(context_t *ctx);
#endif /* !CONTEXT_H_ */
