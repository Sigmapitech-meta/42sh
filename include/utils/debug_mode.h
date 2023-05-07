/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** debug_mode.h
*/

#ifndef WOLOLO_DEBUG_MODE_H
    #define WOLOLO_DEBUG_MODE_H

    #include "utils/attributes.h"
    #include "utils/colors.h"
    #include "epitech.h"

    #define NOTHING /* Nothing */

    #ifdef DEBUG_MODE
        #include <stdio.h>

        #define HEAD_FMT BOLD BLUE "%s" RESET ":" PURPLE BOLD "%d" RESET ": "
        #define COLORED(s) debug_colorize(HEAD_FMT s "\n")
        static const int START = sizeof (HEAD_FMT) - 1;

        #define HEAD __FILE_NAME__, __LINE__
        #define DEBUG(fmt, ...) (printf(COLORED(fmt), HEAD, __VA_ARGS__))
        #define DEBUG_MSG(string) (printf(COLORED(string), HEAD))

        #define DEBUG_CALL(func, ...) func(__VA_ARGS__)

        #define DEBUG_IF(cond, fmt, ...) ((cond) ? DEBUG(fmt, __VA_ARGS__) : 0)
        #define DEBUG_MSG_IF(cond, fmt) ((cond) ? DEBUG_MSG(fmt) : 0)

        #define DEBUG_USED NOTHING
        #define DEBUG_EXPR(...) __VA_ARGS__

    #else
        #define DEBUG(...) NOTHING
        #define DEBUG_MSG(...) NOTHING

        #define DEBUG_CALL(...) NOTHING
        #define DEBUG_IF(...) NOTHING
        #define DEBUG_MSG_IF(...) NOTHING

        #define DEBUG_USED __attribute__((unused))
        #define DEBUG_EXPR(...) /* nop */
    #endif

    #ifdef DEBUG_MODE
        #define ARR_SIZE(arr) (sizeof (arr) / sizeof(arr[0]))

typedef struct {
    const char flag;
    const char *color;
} debug_color_t;

// Todo: Improve using a custom lookahead format instead of guessing from spec.
//  Maybe & os the lookahead and ~ to reset.
static const debug_color_t FLAGS_COLORS[] = {
    {'s', CYAN}, {'d', YELLOW}, {'i', RED},
};

static const size_t FLAGS_COLORS_SIZE = ARR_SIZE(FLAGS_COLORS);
static const size_t FLAG_COL_SIZE = (COLORS_STRING_SIZE + RESET_STRING_SIZE);

char *debug_colorize(char *fmt);
    #endif

#endif /* !WOLOLO_DEBUG_MODE_H */
