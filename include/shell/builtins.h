/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** builtins.h
*/

#ifndef SHELL_BUILTINS_H
    #define SHELL_BUILTINS_H

    #define CONST_ARR_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

typedef _Bool bool_t;
typedef struct context_s context_t;

typedef struct {
    char *name;
    void (*handler)(context_t *ctx);
} builtin_t;

bool_t builtins_check(context_t *ctx);
void builtin_cd(context_t *ctx);
void builtin_exit(context_t *ctx);
void builtin_env(context_t *ctx);
void builtin_setenv(context_t *ctx);
void builtin_unsetenv(context_t *ctx);
#endif /* !SHELL_BUILTINS_H */
