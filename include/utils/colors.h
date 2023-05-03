/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** colors.h
*/

#ifndef COLORS_H_
    #define COLORS_H_

    #define COL_FMT(n) "\e[" #n "m"

    #define RESET COL_FMT(0)
    #define BOLD COL_FMT(1)

    #define GREEN COL_FMT(32)
    #define BLUE COL_FMT(34)
    #define PURPLE COL_FMT(35)
    #define CYAN COL_FMT(36)

#endif /* !COLORS_H_ */
