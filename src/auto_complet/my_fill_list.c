/*
** EPITECH PROJECT, 2023
** my_fill_list.c
** File description:
** to fill the list of binary files
*/

list_t my_get_bin_list(char *env)
{
    char **path = my_get_path(env);
    char **alias = my_get_alias();
    list_t *bins = list_create();

    for (int i = 0; path[i]; i ++)
        if (access(path[i], X_OK) == 0)
            list_append(bins, path[i]);
    for (int i = 0; alias[i]; i ++)
        list_append(bins, alias[i]);
    return bins;
}
