/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** debug_mode.h
*/

#ifndef WOLOLO_DEBUG_MODE_H
    #define WOLOLO_DEBUG_MODE_H

    #define NOTHING /* Nothing */

    #ifdef DEBUG_MODE
        #include <stdio.h>

        #define BLUE "\e[34m"
        #define RESET "\e[0m"

        #define COLORED(s) (BLUE "?" RESET " " s "\n")

        #define DEBUG(fmt, ...) (printf(COLORED(fmt), __VA_ARGS__))
        #define DEBUG_MSG(string) (printf(COLORED(string)))

        #define DEBUG_CALL(func, ...) func(__VA_ARGS__)

        #define DEBUG_IF(cond, fmt, ...) ((cond) ? DEBUG(fmt, __VA_ARGS__) : 0)
        #define DEBUG_MSG_IF(cond, fmt) ((cond) ? DEBUG_MSG(fmt) : 0)

        #define DEBUG_USED NOTHING
        #define DEBUG_EXPR(func) func

        #define DEBUG_SKIP(expr) NOTHING
        #define DEBUG_ALT(expr, debug_expr) debug_expr

    #else
        #define DEBUG(...) NOTHING
        #define DEBUG_MSG(...) NOTHING

        #define DEBUG_CALL(...) NOTHING
        #define DEBUG_IF(...) NOTHING
        #define DEBUG_MSG_IF(...) NOTHING

        #define DEBUG_USED __attribute__((unused))
        #define DEBUG_EXPR(func) NOTHING

        #define DEBUG_SKIP(expr) expr
        #define DEBUG_ALT(expr, debug_expr) expr
    #endif

#endif /* !WOLOLO_DEBUG_MODE_H */
