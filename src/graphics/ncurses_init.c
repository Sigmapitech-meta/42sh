/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** ncurses_init.c
*/

#include <ncurses.h>

#include "graphics.h"

void handle_resize(game_t *game)
{
    endwin();
    refresh();
    clear();
    wresize(game->win, LINES, COLS);

    if (game->is_size_ok)
        if (MIN_WIDTH > COLS || MIN_HEIGHT > LINES)
            return resize_error(game);
    if (!game->is_running)
        return;
    game->is_size_ok = (COLS >= MIN_WIDTH && LINES >= MIN_HEIGHT);
}

void handle_input(game_t *game)
{
    int key = wgetch(game->win);
    if (key == KEY_ESCAPE)
        game->is_running = false;
    if (key == KEY_RESIZE)
        handle_resize(game);
    if (!game->is_size_ok)
        return;
}

void resize_error(game_t *game)
{
    game->is_size_ok = false;
    wclear(game->win);
    while (!game->is_size_ok && game->is_running) {
        mvwprintw(
            game->win,
            LINES / 2, COLS / 2,
            "Minimum size: %dx%d",
            MIN_WIDTH, MIN_HEIGHT
        );
        mvwprintw(
            game->win,
            LINES / 2 + 1, COLS / 2,
            "Current size: %dx%d",
            COLS, LINES
        );
        wrefresh(game->win);
        handle_input(game);
    }
}

void ncurses_update(game_t *game)
{
    clear();
    while (game->is_running) {
        handle_input(game);
        mvprintw(5, 5, "Hello world\n");
        refresh();
    }
}

void ncurses_init(void)
{
    game_t game = {0};

    game.win = initscr();
    game.is_running = TRUE;
    game.is_size_ok = TRUE;
    curs_set(0);
    keypad(game.win, TRUE);
    ncurses_update(&game);
    endwin();
}
