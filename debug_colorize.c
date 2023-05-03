/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** debug_colorize.c
*/

#include <string.h>
#include <malloc.h>

#include "utils/colors.h"
#include "utils/debug_mode.h"

static
int write_color(char *str, char flag)
{
    for (int i = 0; i < FLAGS_COL_COUNT; i++)
        if (flag == FLAGS_COLORS[i].flag)
            return snprintf(
                str, FLAG_COL_SIZE + 3, "%s%%%c%s",
                FLAGS_COLORS[i].color, flag, RESET
            );
    return snprintf(str, 3, "%%%c", flag);
}

char *debug_colorize(char *fmt)
{
    size_t len = strlen(fmt);
    int start = (strstr(fmt, "!") - fmt);
    char *colorized;
    size_t w = 0;

    for (int i = 0; fmt[i]; i++)
        if (i > start && fmt[i] == '%' && fmt[i + 1])
            len += FLAG_COL_SIZE;
    colorized = malloc(len * sizeof(char));
    if (!colorized)
        return fmt;
    for (int i = 0; fmt[i]; i++) {
        if (i == start)
            continue;
        if (i > start && fmt[i] == '%' && fmt[i + 1])
            w += write_color(colorized + w, fmt[++i]);
        else
            colorized[w++] = fmt[i];
    }
    return colorized;
}
