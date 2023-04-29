/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** graphics.h
*/

#ifndef GRAPHICS_H_
    #define GRAPHICS_H_

    #include "epitech.h"

static const int MIN_HEIGHT = 8;
static const int MIN_WIDTH = 128;

static const int KEY_ESCAPE = 27;

typedef struct game {
    bool_t is_running;
    bool_t is_size_ok;
    WINDOW *win;
} game_t;

void resize_error(game_t *game);

#endif /*GRAPHICS_H_*/
