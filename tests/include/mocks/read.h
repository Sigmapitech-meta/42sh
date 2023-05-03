/*
** EPITECH PROJECT, 2023
** Kepler
** File description:
** mocks.h
*/

#ifndef MOCK_read_H_
    #define MOCK_read_H_

    #define real_read __real_read
    #define wrap_read __wrap_read

    #define READ_SWITCH (*switch_read())
    #define BREAK_READ .init RAW_EQ break_read, .fini RAW_EQ fix_read

typedef _Bool bool_t;
typedef struct {
    bool_t is_broken;
} sw_read_t;

sw_read_t *switch_read(void);

void *wrap_read(size_t size);
void *real_read(size_t size);

extern void fix_read(void);
extern void break_read(void);

#endif /* !MOCK_READ_H_ */
