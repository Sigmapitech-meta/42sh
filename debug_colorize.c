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
    for (size_t i = 0; i < FLAGS_COLORS_SIZE; i++)
        if (flag == FLAGS_COLORS[i].flag)
            return snprintf(
                str, FLAG_COL_SIZE + 3, "%s%%%c%s",
                FLAGS_COLORS[i].color, flag, RESET
            );
    return snprintf(str, 3, "%%%c", flag);
}

static
char *debug_colorize_fill(char *colorized, char *fmt)
{
    static char *last = NULL;
    size_t index = 0;

    if (last)
        free(last);
    last = colorized;
    if (!fmt)
        return NULL;
    for (int i = 0; fmt[i]; i++) {
        if (i > START && fmt[i] == '%' && fmt[i + 1])
            index += write_color(colorized + index, fmt[++i]);
        else
            colorized[index++] = fmt[i];
    }
    return colorized;
}

char *debug_colorize(char *fmt)
{
    size_t len = strlen(fmt);
    char *colorized;

    for (int i = 0; fmt[i]; i++)
        if (i > START && fmt[i] == '%' && fmt[i + 1])
            len += FLAG_COL_SIZE;
    colorized = malloc((len + 1) * sizeof(char));
    if (!colorized)
        return fmt;
    colorized[len] = '\0';
    return debug_colorize_fill(colorized, fmt);
}

DESTRUCTOR USED
void clean_up_me_mess(void)
{
    debug_colorize_fill(NULL, NULL);
}
