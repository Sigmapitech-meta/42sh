/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** attributes.h
*/

#ifndef K_ATTRIBUTES_H_
    #define K_ATTRIBUTES_H_

    #define ATTR(key) __attribute__((key))

    #define ALWAYS_INLINE ATTR(always_inline)

    #define USED ATTR(used)
    #define UNUSED ATTR(unused)

    #define CONSTRUCTOR ATTR(constructor)
    #define DESTRUCTOR ATTR(destructor)

#endif /* !K_ATTRIBUTES_H_ */
