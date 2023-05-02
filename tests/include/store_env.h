/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** store_env.h
*/

#ifndef STORE_ENV_H_
    #define STORE_ENV_H_

    #define ENV_STORE(...) (*store())

void **store(void);

#endif /* !STORE_ENV_H_ */
