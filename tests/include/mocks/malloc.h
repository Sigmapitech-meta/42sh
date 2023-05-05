/*
** EPITECH PROJECT, 2023
** Kepler
** File description:
** mocks.h
*/

#ifndef MOCK_MALLOC_H_
    #define MOCK_MALLOC_H_

    #define real_malloc __real_malloc
    #define wrap_malloc __wrap_malloc

    #define MALLOC_SWITCH (*switch_malloc())
    #define BREAK_MALLOC .init RAW_EQ break_malloc, .fini RAW_EQ fix_malloc

typedef _Bool bool_t;
typedef struct {
    bool_t is_broken;
    size_t last_allocated;
} sw_malloc_t;

sw_malloc_t *switch_malloc(void);

void *wrap_malloc(size_t size);
void *real_malloc(size_t size);

extern void fix_malloc(void);
extern void break_malloc(void);

#endif /* !MOCK_MALLOC_H_ */
