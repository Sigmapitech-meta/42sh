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
#include "utils/cleanup.h"

size_t file_get_size(char const *filepath)
{
    stat_t buffer;

    return SENTINEL_OR(
        stat(filepath, &buffer),
        buffer.st_size
    );
}

char *file_read_fd(int fd, size_t filesize)
{
    char *content;

    if (IS_SENTINEL_OF(filesize, size_t))
        return NULL;
    content = malloc((filesize + 1) * sizeof(char));
    if (!content)
        return NULL;
    content[filesize] = '\0';
    if (!IS_SENTINEL_OF(read(fd, content, filesize), ssize_t))
        return content;
    free(content);
    return NULL;
}

char *file_read(char const *filepath)
{
    AUTO_CLOSE int fd = open(filepath, O_RDONLY);

    return (
        IS_SENTINEL(fd) ?
        NULL : file_read_fd(fd, file_get_size(filepath))
    );
}
