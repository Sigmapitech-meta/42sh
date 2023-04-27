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

    #define _CLEAN_UP_CALL cleanup(free_stack)

    #define AUTOFREE ATTR(_CLEAN_UP_CALL)
    #define ALWAYS_INLINE ATTR(always_inline)

ALWAYS_INLINE USED
static inline void free_stack(void *ptr)
{
    if (ptr)
        free(*(void **) ptr);
}

#endif /* !AUTOFREE_H_ */
