/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** history.h
*/

#ifndef HISTORY_H_
    #define HISTORY_H_

    #include "list.h"
    #include "epitech.h"

typedef struct command_s command_t;
typedef struct context_s context_t;

typedef struct history_s {
    file_t *write_stream;
    list_t *pool;
} history_t;

history_t *history_create(void);
void history_append(history_t *hist, char *input);
void history_destroy(history_t *hist);

list_t *save_open(void);

#endif /* !HISTORY_H_ */
