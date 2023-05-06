/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** str_replace.c
*/

#include <stdlib.h>
#include <string.h>

#include "base.h"
#include "utils/debug_mode.h"

static
int str_replace_count(char *src, char *from)
{
    int count = 0;
    size_t len = strlen(from);

    for (int i = 0; src[i]; i++) {
        if (!strncmp(src + i, from, len)) {
            i += (len - 1);
            count++;
        }
    }
    return count;
}

static
char *str_replace_fill(char *out, char *src, char *from, char *to)
{
    int write_index = 0;
    size_t len = strlen(from);
    size_t len_to = strlen(to);

    for (int i = 0; src[i]; i++) {
        if (!strncmp(src + i, from, len)) {
            strcpy(out + write_index, to);
            write_index += len_to;
            i += (len - 1);
        } else
            out[write_index++] = src[i];
    }
    DEBUG("[[%s]]", out);
    return out;
}

char *str_replace(char *src, char *from, char *to)
{
    size_t new_len;
    int count = str_replace_count(src, from);
    char *out;

    if (count < 1)
        return src;
    new_len = strlen(src) - (strlen(from) * count) + (strlen(to) * count);
    if (new_len <= 0)
        return src;
    out = malloc((new_len + 1) * sizeof (char));
    if (!out)
        return src;
    out[new_len] = '\0';
    DEBUG("%d -> %d", count, new_len);
    return str_replace_fill(out, src, from, to);
}
