/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** gethostname.h
*/

#ifndef MOCK_GETHOSTNAME_H_
    #define MOCK_GETHOSTNAME_H_

    #define real_gethostname __real_gethostname
    #define wrap_gethostname __wrap_gethostname

    #define IS_GETHOSTNAME_BROKEN (*switch_gethostname())

typedef _Bool bool_t;

bool_t *switch_gethostname(void);

void wrap_gethostname(char *name, size_t len);
void real_gethostname(char *name, size_t len);

void fix_gethostname(void);
void break_gethostname(void);

#endif /* !MOCK_GETHOSTNAME_H_ */
