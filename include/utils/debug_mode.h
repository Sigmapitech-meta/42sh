/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** debug_mode.h
*/

#ifndef WOLOLO_DEBUG_MODE_H
    #define WOLOLO_DEBUG_MODE_H

    #include "utils/colors.h"

    #define NOTHING /* Nothing */

    #ifdef DEBUG_MODE
        #include <stdio.h>

        #define HEAD_FMT "[" CYAN "%s" RESET ":" GREEN "%d" RESET "] "
        #define COLORED(s) (HEAD_FMT BLUE "?" RESET " " s "\n")

        #define HEAD CYAN __FILE_NAME__, __LINE__
        #define DEBUG(fmt, ...) (printf(COLORED(fmt), HEAD, __VA_ARGS__))
        #define DEBUG_MSG(string) (printf(COLORED(string), HEAD))

        #define DEBUG_CALL(func, ...) func(__VA_ARGS__)

        #define DEBUG_IF(cond, fmt, ...) ((cond) ? DEBUG(fmt, __VA_ARGS__) : 0)
        #define DEBUG_MSG_IF(cond, fmt) ((cond) ? DEBUG_MSG(fmt) : 0)

        #define DEBUG_USED NOTHING
        #define DEBUG_EXPR(func) func

    #else
        #define DEBUG(...) NOTHING
        #define DEBUG_MSG(...) NOTHING

        #define DEBUG_CALL(...) NOTHING
        #define DEBUG_IF(...) NOTHING
        #define DEBUG_MSG_IF(...) NOTHING

        #define DEBUG_USED __attribute__((unused))
        #define DEBUG_EXPR(func) /* nop */
    #endif

#endif /* !WOLOLO_DEBUG_MODE_H */
