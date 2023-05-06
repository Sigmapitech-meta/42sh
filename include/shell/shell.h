/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** shell.h
*/

#ifndef SHELL_H
    #define SHELL_H

    #define MAX_ARG_COUNT (2)

extern char **environ;

static const size_t MINIMAL_INPUT_CHECK = 2;

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

typedef struct command_s {
    int argc;
    char **argv;
} command_t;

typedef struct context_s {
    command_t *cmd;
    unsigned short status;
    bool_t is_running;
    bool_t ran_from_tty;
    char *user_input;
    char *prev_dir;
    size_t input_size;
    char **original_env;
} context_t;

int command_run_subprocess(context_t *ctx);

int shell_run_from_env(char **env);
void shell_run_from_ctx(context_t *ctx);

bool_t shell_read_line(context_t *ctx);
void shell_evaluate(context_t *ctx);

void prompt_display(void);

char *env_get_setter(char *key, char *value);
void env_free_key(char *key, char **original_env);
void env_free(char **original_env);

#endif /* !SHELL_H */
