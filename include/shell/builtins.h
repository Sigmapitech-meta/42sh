/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** builtins.h
*/

#ifndef SHELL_BUILTINS_H
    #define SHELL_BUILTINS_H

    #define CONST_ARR_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

    #include "shell/shell.h"
    #include "utils/attributes.h"
    #include "utils/debug_mode.h"

typedef _Bool bool_t;
typedef struct context_s context_t;

typedef struct {
    char *name;
    void (*handler)(context_t *ctx);
} builtin_t;

/**
 * @brief check if the builtin is valid
 *
 * @param ctx context
 * @return bool_t : true if the builtin is valid
 */
bool_t builtins_check(context_t *ctx);
void builtin_alias(context_t *ctx);
/**
 * @brief Get the builtin id
 *
 * @param cmd_name
 * @return int : the builtin id
 */
int get_builtin_id(char *cmd_name);

/**
 * @brief echo command
 *
 * @param ctx context
 * @return USED
 */
static inline
USED void builtin_echo(context_t *ctx)
{
    command_run_subprocess(ctx);
}

/**
 * @brief cd command
 *
 * @param ctx : context
 */
void builtin_cd(context_t *ctx);
/**
 * @brief exit command
 *
 * @param ctx : context
 */
void builtin_exit(context_t *ctx);
/**
 * @brief setenv command
 *
 * @param ctx : context
 */
void builtin_setenv(context_t *ctx);
/**
 * @brief unsetenv command
 *
 * @param ctx : context
 */
void builtin_unsetenv(context_t *ctx);
/**
 * @brief which command
 *
 * @param ctx : context
 */
void builtin_which(context_t *ctx);
/**
 * @brief where command
 *
 * @param ctx : context
 */
void builtin_where(context_t *ctx);

DEBUG_EXPR(
    /**
     * @brief getenv command
     *
     * @param ctx : context
     */
    void builtin_getenv(context_t *ctx);
    /**
     * @brief prevdir command
     *
     * @param ctx : context
     */
    void builtin_prev_dir(context_t *ctx);
);

USED
static const builtin_t BUILTINS[] = {
    {"alias", &builtin_alias},
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

/**
 * @brief number of builtins
 *
 */
static const int BUILTIN_COUNT = CONST_ARR_SIZE(BUILTINS);

#endif /* !SHELL_BUILTINS_H */
