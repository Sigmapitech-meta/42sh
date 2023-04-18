/*
** EPITECH PROJECT, 2023
** Lib ido
** File description:
** Character mapping
*/

#ifndef EPITECH_EXIT_STATE_H
    #define EPITECH_EXIT_STATE_H

    #define EXIT_MSG(msg, w, v) (w(msg) ? v : v)

    #define EXIT_KO_MSG(msg) EXIT_MSG(msg, W_ERROR_C, EXIT_KO)
    #define EXIT_OK_MSG(msg) EXIT_MSG(msg, W_OUTPUT_C, EXIT_OK)

enum {
    EXIT_OK = 0,
    EXIT_KO = 84
};

#endif /* !EPITECH_EXIT_STATE_H */
