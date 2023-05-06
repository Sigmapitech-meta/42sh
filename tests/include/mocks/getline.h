/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** getline.h
*/

#ifndef MOCK_GETLINE_H_
    #define MOCK_GETLINE_H_

    #include "coding_style_fix.h"
    #include "utils/attributes.h"

    #define real_getline __real_getline
    #define wrap_getline __wrap_getline

    #define GETLINE_DATA (getline_mock_ptr())

    #include <stdio.h>

typedef FILE file_t;

typedef enum {
    BROKEN,
    NORMAL,
    TABLE
} gl_mode_t;

typedef struct {
    gl_mode_t mode;
    char **table;
} gl_mock_t;

gl_mock_t *getline_mock_ptr(void);

ssize_t wrap_getline(char **line, size_t *read, file_t *stream);
ssize_t real_getline(char **line, size_t *read, file_t *stream);

#endif /* !MOCK_GETLINE_H_ */
