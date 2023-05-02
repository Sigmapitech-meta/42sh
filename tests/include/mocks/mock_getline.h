/*
** EPITECH PROJECT, 2023
** Kepler
** File description:
** mocks.h
*/

#ifndef MOCK_GETLINE_H_
    #define MOCK_GETLINE_H_

    #include "epitech/norm.h"
#include "utils/attributes.h"

#define real_getline __real_getline
    #define wrap_getline __wrap_getline

    #define GETLINE_TOGGLE (*getline_activation_ptr())
    #define ARR_SIZE(arr) (sizeof (arr) / sizeof(arr[0]))

    #include <stddef.h>

typedef FILE file_t;

ssize_t wrap_getline(char **line, size_t *read, file_t *stream);
ssize_t real_getline(char **line, size_t *read, file_t *stream);

void use_mock_getline(void);
void use_normal_getline(void);

USED
static const char *GETlINE_TABLE[] = {
    "Hello\n",
    "this\n",
    "is\n",
    "my\n",
    "friend\n",
    "Albert!\n"
};

static const int GETLINE_TABLE_LENGTH = ARR_SIZE(GETlINE_TABLE);

#endif /* !MOCK_GETLINE_H_ */
