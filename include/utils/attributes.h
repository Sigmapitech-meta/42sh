/*
** EPITECH PROJECT, 2023
** lem-in
** File description:
** k_attributes.h
*/

#ifndef K_ATTRIBUTES_H_
    #define K_ATTRIBUTES_H_

    #define ATTR(key) __attribute__((key))

    #define USED ATTR(used)
    #define UNUSED ATTR(unused)

    #define CONSTRUCTOR ATTR(constructor)
    #define DESTRUCTOR ATTR(destructor)

#endif /* !K_ATTRIBUTES_H_ */
