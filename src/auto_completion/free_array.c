/*
** EPITECH PROJECT, 2023
** free_array.c
** File description:
** to free an array
*/

int free_array(char **array)
{
    for (int i = 0; array[i]; i ++)
        free(array[i]);
    free(array);
    return 0;
}
