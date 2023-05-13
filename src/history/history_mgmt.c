/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** history_mgmt.c
*/

#include <string.h>

#include "shell/history.h"

void history_destroy_pool(list_t *list)
{
    if (!list)
        return;
    LIST_FOREACH(list, node)
        free(node->value);
    list_destroy(list);
}

void history_destroy(history_t *hist)
{
    if (!hist)
        return;
    history_destroy_pool(hist->pool);
    fclose(hist->write_stream);
    free(hist);
}

void history_append(history_t *hist, char *input)
{
    if (!hist)
        return;
    if (IS_SENTINEL_OF(list_append(hist->pool, input), ssize_t))
        return;
    fflush(hist->write_stream);
    fprintf(hist->write_stream, "%s\n", input);
}

history_t *history_create()
{
    history_t *hist = malloc(sizeof(*hist));

    if (!hist)
        return NULL;
    hist->pool = save_open();
    if (!hist->pool)
        return NULL;
    hist->write_stream = fopen(".42sh_history" , "a+");
    if (!hist->write_stream) {
        history_destroy_pool(hist->pool);
        return NULL;
    }
    return hist;
}