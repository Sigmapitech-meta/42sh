/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** sentinel.h
*/

#ifndef WOLO_SENTINEL_H
    #define WOLO_SENTINEL_H

    #define SENTINEL (-1)
    #define SENTINEL_OF(type) (type)(SENTINEL)

    #define IS_SENTINEL(expr) (expr == SENTINEL)
    #define IS_SENTINEL_OF(expr, type) (expr == SENTINEL_OF(type))

    #define ON_SENTINEL(expr) if (IS_SENTINEL(expr))

    #define SENTINEL_OR(c, e) (IS_SENTINEL(c) ? SENTINEL : (e))

#endif
