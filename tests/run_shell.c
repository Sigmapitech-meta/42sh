/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** run_shell.c
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "run_shell_command.h"
#include "shell/shell.h"
#include "utils/attributes.h"
#include "epitech.h"
#include "utils/sentinel.h"
#include "store_env.h"

void **store(void)
{
    static void *ptr = NULL;

    return &ptr;
}

CONSTRUCTOR
void store_env(int argc UNUSED, char **argv UNUSED, char **env)
{
    ENV_STORE(&store) = env;
}

int run_shell_command(char *command)
{
    command_t cmd = { 0 };
    context_t ctx = {
        .cmd = &cmd, 0,
        .original_env = ENV_STORE(&store_env),
        .input_size = strlen(command) + 1,
        .user_input = malloc((ctx.input_size + 1) * sizeof (char)),
        .is_running = TRUE
    };

    if (!ctx.user_input)
        return W_SENTINEL;
    snprintf(ctx.user_input, ctx.input_size + 1, "%s\n", command);
    shell_evaluate(&ctx);
    free(ctx.prev_dir);
    env_free(ctx.original_env);
    return ctx.status;
}
