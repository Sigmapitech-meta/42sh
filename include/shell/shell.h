/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** context.h
*/

#ifndef SHELL_H
    #define SHELL_H

    #define MAX_ARG_COUNT (2)

    #define ENV_FIND_FIXED(env, name) env_find(env, name, sizeof(name) - 1)
    #define ENV_FIND_VAR(env, name) (ENV_FIND_FIXED(env, name "="))

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
typedef struct list_s list_t;
typedef unsigned long size_t;

typedef struct command_s {
    int argc;
    char **argv;
} command_t;

typedef struct context_s {
    unsigned char status;
    bool_t is_running;
    bool_t ran_from_tty;
    list_t *env;
    char *user_input;
    char *prev_dir;
    size_t input_size;
    command_t *cmd;
} context_t;

bool_t command_run_subprocess(context_t *ctx);
int shell_run_from_env(char **env);

list_t *env_parse(char **env);
char **env_rebuild(list_t *env);
int env_find(list_t *env, char *name, int n);

void prompt_display(context_t *ctx);

#endif /* !SHELL_H */
