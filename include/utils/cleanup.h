/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** cleanup.h
*/


#ifndef CLEAN_UP_H
    #define CLEAN_UP_H

    #include <stdlib.h>
    #include <unistd.h>

    #include "utils/attributes.h"

/* The coding style uses the following regex to check for function names:
 * (?P<beforeFunction>(^|#.+|(?<=[;}{]))([\n\s*\/]*(^|(?<=[\n\s{};]))))
 * (?P<func>(?P<type>((?!break\W|case\W|continue\W|default\W|do\W|else
 * \W|for\W|goto\W|if\W|return\W|sizeof\W|switch\W|typedef\W|while\W)
 * \w+[\w\s\n*,]*|(\w+[\s\t\n*]+)\(\*.*\)\(.*\))[\s\n*]+)
 * (?P<name>(?<=[\n\s*])\w+)[\s\n]*\([\n\s]*(?P<args>[^;{]*)[\n\s]*\)[\s\n]*
 * (?P<functionStartChar>[;{]{1}))
 *
 * As we all know, C is a simple language,
 * but it comes with a lot of possible parsing pitfalls.
 * Regex is not a good solution to try parsing it.
 *
 * This regex is broken as hell, falsely detecting parametric macros
 * that don't have parenthesis around their replacement as a function.
 *
 * Thus, we have to use a quite magic `// {` expression that break the regex
 * to avoid that false-positive. Since this expression is unused, we place it
 * in a $$ macro.
 *
 * Again, fixing the coding style by using one of its numerous bugs...
 **/

    #define ON_CLEANUP(func) ATTR(cleanup(func))

    #define AUTOCLOSE ON_CLEANUP(close_file)
    #define $$ ({}) /* Fix your coding style lmao */

    #define AUTOFREE ON_CLEANUP(free_stack)
    #define $$ ({}) /* Fix your coding style lmao */

    #define ALWAYS_INLINE ATTR(always_inline)
    #define $$ ({}) /* Fix your coding style lmao */

ALWAYS_INLINE USED
static inline void free_stack(void *ptr_ptr)
{
    void *ptr = *(void **)ptr_ptr;

    if (ptr)
        free(ptr);
}

ALWAYS_INLINE USED
static inline void close_file(void *fd_ptr)
{
    int fd = *(int *)fd_ptr;

    if (fd)
        close(fd);
}

#endif /* !CLEAN_UP_H */
