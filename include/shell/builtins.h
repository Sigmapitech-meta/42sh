/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** builtins.h
*/
#ifndef BUILTINS_H_
    #define BUILTINS_H_

    #define CONST_ARR_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

typedef struct context_s context_t;

typedef struct {
    char *name;
    void (*handler)(context_t *ctx);
} builtin_t;

void builtin_cd(context_t *ctx);
void builtin_exit(context_t *ctx);
void builtin_env(context_t *ctx);
void builtin_setenv(context_t *ctx);
void builtin_unsetenv(context_t *ctx);
#endif /* !BUILTINS_H_ */
