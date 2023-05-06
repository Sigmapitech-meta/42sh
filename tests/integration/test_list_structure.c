/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test_list_structure.c
*/

#include <criterion/criterion.h>

#include "base.h"
#include "epitech/sputnik.h"
#include "list.h"
#include "utils/sentinel.h"
#include "mocks/malloc.h"

static
list_t * create_test_list(char *words[6])
{
    int ret;
    list_t *lst = list_create();

    if (!lst)
        return NULL;
    for (int i = 0; i < 6; i++) {
        ret = list_append(lst, words[i]);
        if (ret == SENTINEL)
            return NULL;
        CR_ASSERT_EQ(ret, i);
    }
    return lst;
}

static
void check_nodes(list_t *lst, char *words[6])
{
    list_node_t *node;

    CR_ASSERT_EQ(lst->size, 6);
    for (int index = 0; index < 6; index++) {
        node = list_get_node(lst, index);
        CR_ASSERT_EQ(node->value, words[index]);
        if (!index)
            CR_ASSERT_NOT(node->prev);
        if (index != 5)
            CR_ASSERT(node->next);
    }
}

static
void check_list_remove_clear(list_t *lst, char *words[6])
{
    list_remove(lst, 0);
    for (int i = 0; i < 4; i++)
        CR_ASSERT_EQ(list_get(lst, i), words[i + 1]);
    list_clear(lst);
    CR_ASSERT_NOT(lst->head);
    CR_ASSERT_NOT(lst->tail);
    CR_ASSERT_NOT(lst->size);
}

TEST(lst, integration)
$ {
    char *words[6] = {"Hello", "this", "is", "my", "friend", "albert"};
    list_t *lst = create_test_list(words);

    if (!lst)
        return;
    check_nodes(lst, words);
    check_list_remove_clear(lst, words);
    list_destroy(lst);
}

TEST(lst, broken_malloc, TEST_USE(break_malloc, fix_malloc))
{
    char *words[6] = {"Hello", "this", "is", "my", "friend", "albert"};
    list_t *lst = create_test_list(words);
    list_t empty = { 0 };
    int ret;

    CR_ASSERT_NOT(lst);
    ret = list_append(&empty, words[0]);
    CR_ASSERT_EQ(ret, SENTINEL);
}
