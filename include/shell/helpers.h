/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** helpers.h
*/

#ifndef HELPERS_H_
    #define HELPERS_H_

long file_get_size(char const *filepath);
char *file_read_fd(int fd, size_t filesize);
char *file_read(char *filepath);

#endif /* !HELPERS_H_ */
