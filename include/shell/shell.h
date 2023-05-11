/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** shell.h
*/

#ifndef SHELL_H
    #define SHELL_H

    #include <string.h>
    #include <sys/wait.h>

    #include "base.h"
    #include "epitech.h"

    #include "utils/colors.h"
    #include "utils/cleanup.h"

    #define MAX_ARG_COUNT (2)
    #define MAX_SHORT_LENGTH (6)
    #define MAX_INT_LEN (12)

    #define HOSTNAME_MAX_LEN 64

    #define PROMPT_BOX(item) BOLD BLUE "[" item BOLD BLUE "]" RESET
    #define USER_HOST GREEN "%s" RESET BOLD "@" CYAN "%s"
    #define PWD RESET BOLD "%s" BLUE

extern char **environ;

USED static const char *FORMAT_PROMPT = (
    BOLD BLUE "┌─" PROMPT_BOX(USER_HOST) " - " PROMPT_BOX(PWD) "\n"
    BOLD BLUE "└─" PROMPT_BOX(PURPLE "$") " "
);

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

enum {
    FLOATING_EXCEPTION = 8,
    SENTINEL_DETECT = 65280,
    SEGFAULT = 11,
    _CORE_DUMP = 128,
    SEGFAULT_CORE_DUMP = SEGFAULT | _CORE_DUMP
};

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

/** @brief Retrieve string composed by `$key = $val` */
char *env_get_setter(char *key, char *value);

/** @brief free a key */
void env_free_key(char *key, char **original_env);

/** @brief free the env */
void env_free(char **original_env);

char *replace_var(context_t *ctx, char *input);

/** @brief Concatenate two paths */
char *path_concat(char *left, char *right);

/** @brief Retrieve the path of a command */
char *path_find_cmd(char *cmd);

/** @brief Retrieve the command path if it can be accessed */
char *path_find_access(char *path, char *cmd);

/** @brief set a environment variable and handle necessary cleanups */
bool_t putenv_safe(char *key, char *value, char **original_env);

/* @brief Replace a key-value within input context */
char *pre_parse_replace(context_t *ctx, char *from, char *to, char *input);

/** @brief Print the status message for a given code */
static inline
USED void status_show(int status)
{
    if (status == EXIT_KO) {
        EPRINTF("Error Handling\n");
        return;
    }
    if (!WIFEXITED(status) && WIFSIGNALED(status)) {
        if (WTERMSIG(status) != FLOATING_EXCEPTION)
            EPRINTF("%s", strsignal(WTERMSIG(status)));
        else
            EPRINTF("Floating exception");
        if (WCOREDUMP(status))
            EPRINTF(" (core dumped)");
        EPRINTF("\n");
    }
}

/** @brief display prompt */
static inline
USED void prompt_display(void)
{
    AUTOFREE char *current_dir = getcwd(NULL, 0);
    char hostname[HOSTNAME_MAX_LEN];
    char *username = getenv("USER");

    hostname[HOSTNAME_MAX_LEN - 1] = '\0';
    gethostname(hostname, HOSTNAME_MAX_LEN - 1);
    printf(FORMAT_PROMPT, username, hostname, current_dir);
}


#endif /* !SHELL_H */
