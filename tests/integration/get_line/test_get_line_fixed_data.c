/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_get_line_fixed_data.c
*/

#include "base.h"
#include "epitech/sputnik.h"
#include "mocks/getline.h"

#include "utils/autofree.h"
#include "utils/sentinel.h"

static
void enable_mock(void)
{
    gl_mock_t *mock_data = GETLINE_DATA;
    char **mem_table;
    char *base_table[] = {"Hello", "this\n", "is\n", "albert\n", NULL};
    int table_size = 0;

    for (; base_table[table_size]; table_size++);
    mem_table = calloc(sizeof (char *), table_size + 1);
    for (int i = 0; base_table[i]; i++) {
        mem_table[i] = strdup(base_table[i]);
        if (!mem_table[i])
            return;
    }
    mock_data->mode = TABLE;
    mock_data->table = mem_table;
}

static
void disable_mock(void)
{
    gl_mock_t *mock_data = GETLINE_DATA;
    gl_mode_t prev_mode = mock_data->mode;
    char **table = mock_data->table;

    mock_data->mode = NORMAL;
    if (prev_mode != TABLE)
        return;
    mock_data->table = NULL;
    for (int i = 0; table[i]; i++)
        free(table[i]);
    free(table);
}

TEST(get_line, getline_fixed_data, TEST_USE(enable_mock, disable_mock))
$ {
    char *line = NULL;
    ssize_t size = get_line(&line);

    while (line) {
        CR_ASSERT(line);
        CR_ASSERT(size > 0);
        size = get_line(&line);
    }
    CR_ASSERT_EQ(size, W_SENTINEL_OF(ssize_t));
}
