/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** file_reader.c
*/

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#include "base.h"
#include "utils/sentinel.h"

size_t file_get_size(char const *filepath)
{
    stat_t buffer;

    return W_SENTINEL_OR(
        stat(filepath, &buffer),
        buffer.st_size
    );
}

char *file_read_fd(int fd, size_t filesize)
{
    long state;
    char *content = malloc((filesize + 1) * sizeof(char));

    if (!content)
        return NULL;
    state = read(fd, content, filesize);
    if (state == W_SENTINEL_OF(long)) {
        free(content);
        return NULL;
    }
    content[state] = '\0';
    return content;
}

char *file_read(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *content = NULL;

    if (fd == W_SENTINEL)
        return NULL;
    content = file_read_fd(fd, file_get_size(filepath));
    close(fd);
    return content;
}
