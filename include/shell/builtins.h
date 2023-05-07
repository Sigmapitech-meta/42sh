/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** builtins.h
*/

#ifndef SHELL_BUILTINS_H
    #define SHELL_BUILTINS_H

    #define CONST_ARR_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

    #include "utils/attributes.h"
    #include "utils/debug_mode.h"

typedef _Bool bool_t;
typedef struct context_s context_t;

typedef struct {
    char *name;
    void (*handler)(context_t *ctx);
} builtin_t;

bool_t builtins_check(context_t *ctx);

void builtin_echo(context_t *ctx);
void builtin_cd(context_t *ctx);
void builtin_exit(context_t *ctx);
void builtin_setenv(context_t *ctx);
void builtin_unsetenv(context_t *ctx);
void builtin_which(context_t *ctx);
void builtin_where(context_t *ctx);

DEBUG_EXPR(
    void builtin_getenv(context_t *ctx);
    void builtin_prev_dir(context_t *ctx);
);

USED
static const builtin_t BUILTINS[] = {
    {"echo", &builtin_echo},
    {"cd", &builtin_cd},
    {"exit", &builtin_exit},
    {"setenv", &builtin_setenv},
    {"unsetenv", &builtin_unsetenv},
    {"which", &builtin_which},
    {"where", &builtin_where},
    DEBUG_EXPR(
        {"getenv", &builtin_getenv},
        {"prevdir", &builtin_prev_dir}
    )
};

static const int BUILTIN_COUNT = CONST_ARR_SIZE(BUILTINS);

#endif /* !SHELL_BUILTINS_H */
