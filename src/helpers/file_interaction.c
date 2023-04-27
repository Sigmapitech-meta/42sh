/*
** EPITECH PROJECT, 2023
** RPG - Map Loader
** File description:
** read a file as a single array
*/

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#include "utils/sentinel.h"

long file_get_size(char const *filepath)
{
    struct stat buffer;
    int state = stat(filepath, &buffer);

    return (state == W_SENTINEL) ? W_SENTINEL : buffer.st_size;
}

char *file_read_fd(int fd, long filesize)
{
    long state;
    char *content = malloc(sizeof(char) * (filesize + 1));

    if (!content)
        return NULL;
    state = read(fd, content, filesize);
    if (state != W_SENTINEL) {
        content[state] = '\0';
        return content;
    }
    free(content);
    return NULL;
}

char *file_read(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *content = NULL;

    if (fd != W_SENTINEL) {
        content = file_read_fd(fd, file_get_size(filepath));
        close(fd);
    }
    return content;
}
