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
#include "epitech/norm.h"

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

IGNORE(
    /** @warning
     * cmd_len variable should not be moved within `ctx.user_input`
     * as gcc will optimize the structure initialization
     * by doing it in multi-threading causing user_input to be
     * 0 at allocation time created a corrupted top size.
    **/
)

int run_shell_command(char *command)
$ {
    size_t cmd_len = strlen(command) + 1;
    command_t cmd = { 0 };
    context_t ctx = {
        .cmd = &cmd, 0,
        .original_env = ENV_STORE(&store_env),
        .user_input = malloc((cmd_len + 1) * sizeof (char)),
        .input_size = cmd_len,
        .is_running = TRUE
    };

    if (!ctx.user_input)
        return SENTINEL;
    snprintf(ctx.user_input, ctx.input_size, "%s\n", command);
    shell_evaluate(&ctx);
    free(ctx.prev_dir);
    env_free(ctx.original_env);
    return ctx.status;
}
