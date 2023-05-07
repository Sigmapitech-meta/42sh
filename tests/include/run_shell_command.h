/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** run_shell_command.h
*/

#ifndef RUN_SHELL_H_
    #define RUN_SHELL_H_

    #include "utils/cleanup.h"

    #define CTX_AUTOFREE ON_CLEANUP(auto_context_destroy)
    #define $$1 ({ /* FIX THE CODING STYLE !!!! */ $$1 })

typedef struct context_s context_t;

/* Run a command in the 42sh */
context_t *run_shell_command(char *command);
void context_destroy(context_t *ctx);

static inline
USED void auto_context_destroy(void *ptr)
{
    context_t *ctx = *(context_t **)ptr;

    context_destroy(ctx);
}

#endif /* !RUN_SHELL_H_ */
