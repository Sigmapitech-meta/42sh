/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** autofree.h
*/


#ifndef AUTOFREE_H_
    #define AUTOFREE_H_

    #include <stdlib.h>

    #include "utils/attributes.h"

    #define AUTOFREE ATTR(CLEAN_UP_CALL)

    #define CLEAN_UP_CALL cleanup(free_stack)

ALWAYS_INLINE USED
static inline void free_stack(void *ptr)
{
    void *real_ptr = *(void **)ptr;

    if (real_ptr)
        free(real_ptr);
}

#endif /* !AUTOFREE_H_ */
