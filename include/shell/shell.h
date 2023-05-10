/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** shell.h
*/

#ifndef SHELL_H
    #define SHELL_H

    #define MAX_ARG_COUNT (2)
    #define MAX_SHORT_LENGTH (6)
    #define MAX_INT_LEN (12)

extern char **environ;

static const size_t MINIMAL_INPUT_CHECK = 2;

/**
 * @brief Prints the usage of the shell
 *
 */
static const char USAGE[] = (
    "Minishell 2 - Usage: ./mysh [-h]\n"
    "\nAll commands in the path are available.\n"
    "Within the shell, press CTRL+D or enter exit to quit.\n"
    "Alternatively, you can provide commands from standard input.\n\n"
    "The following builtins are present:\n"
    "- env, unsetenv, cd, exit\n\n"
    "As long as the following operators:\n"
    "- ; | > < >> <<\n"
);

typedef _Bool bool_t;
typedef unsigned long size_t;

typedef struct list_s list_t;
typedef struct aliases_s aliases_t;

typedef struct command_s {
    int argc;
    char **argv;
} command_t;

typedef struct context_s {
    bool_t is_running;
    bool_t ran_from_tty;
    command_t *cmd;
    char **original_env;
    char *prev_dir;
    char *user_input;
    size_t input_size;
    unsigned short status;
    aliases_t *aliases;
} context_t;

/** @brief Run a command in the shell */
int command_run_subprocess(context_t *ctx);

/** @brief main loop */
int shell_run_from_env(char **env);

/** @brief run a command in the shell* */
void shell_run_from_ctx(context_t *ctx);

/** @brief read user input */
bool_t shell_read_line(context_t *ctx);

/** @brief run a command in the shell */
void shell_evaluate(context_t *ctx);

/** @brief display prompt */
void prompt_display(void);

/** @brief Retrieve string composed by `$key = $val` */
char *env_get_setter(char *key, char *value);

/** @brief free a key */
void env_free_key(char *key, char **original_env);

/** @brief free the env */
void env_free(char **original_env);

char *replace_var(context_t *ctx, char *input);

#endif /* !SHELL_H */
