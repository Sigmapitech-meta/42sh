/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** sentinel.h
*/

#ifndef WOLO_SENTINEL_H
    #define WOLO_SENTINEL_H

    #define W_SENTINEL (-1)
    #define W_SENTINEL_OF(type) (type)(W_SENTINEL)

    #define W_SENTINEL_OR(c, e) ((c == W_SENTINEL) ? W_SENTINEL : (e))

#endif
