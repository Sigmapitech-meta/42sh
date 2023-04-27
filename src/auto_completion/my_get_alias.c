/*
** EPITECH PROJECT, 2023
** my_get_alias.c
** File description:
** my_get_alias.c
*/

#include "shell/auto_completion.h"

static bool is_alias(char *str)
{
    if (my_strlen(str) > 5 && str[0] == 'a' && str[1] == 'l' && str[2] == 'i' &&
        str[3] == 'a' && str[4] == 's')
        return true;
    return false;
}

static int count_alias(char **file_content)
{
    int count = 0;

    for (int i = 0; file_content[i]; i ++)
        if (is_alias(file_content[i]))
            count ++;
    return count;
}

static char **parse_alias(char **file)
{
    int line_nbr = count_alias(file);
    char **alias = my_calloc(sizeof(char *), (line_nbr + 1));
    char **one_alias = NULL;
    int j = 0;

    for (int i = 0; file[i]; i ++)
        if (is_alias(file[i])) {
            one_alias = my_str_split(file[i], " =");
            alias[j ++] = my_strdup(one_alias[1]);
            free_array(one_alias);
        }
    alias[line_nbr] = NULL;
    return alias;
}

char **my_get_alias(void)
{
    char **alias = NULL;
    int fd = open(".42shrc", O_RDONLY);
    char *file_content = NULL;
    struct stat stats;

    stat(".42shrc", &stats);
    file_content = my_calloc(1, stats.st_size + 1);
    read(fd, file_content, stats.st_size);
    file_content[stats.st_size] = '\0';
    alias = my_str_split(str, "\n");
    alias = parse_alias(alias);
    free(file_content);
    return alias;
}
