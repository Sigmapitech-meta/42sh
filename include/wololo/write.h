/*
** EPITECH PROJECT, 2023
** Minishell
** File description:
** Wololo
*/

#ifndef WOLO_WRITE_H
    #define WOLO_WRITE_H

    #define W_WRITE_IMPL(std, str, size) (write(std, str, size))

    #define W_OUTPUT_N(out, n) (W_WRITE_IMPL(STDOUT_FILENO, out, n))
    #define W_ERROR_N(err, n) (W_WRITE_IMPL(STDERR_FILENO, err, n))

    #define W_OUTPUT_C(out) (W_OUTPUT_N(out, sizeof (out) - 1))
    #define W_ERROR_C(err) (W_ERROR_N(err, sizeof (err) - 1))

    #define W_OUTPUT_LINE_C(out) (W_OUTPUT_N(out "\n", sizeof (out)))
    #define W_ERROR_LINE_C(err) (W_ERROR_N(err "\n", sizeof (err)))

#endif
