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

    #include "base.h"
    #include "utils/attributes.h"

    #define ON_CLEANUP(func) ATTR(cleanup(func))

    #define AUTO_CLOSE ON_CLEANUP(close_fd)
    #define AUTO_FCLOSE ON_CLEANUP(close_file)
    #define AUTO_FREE ON_CLEANUP(free_stack)

    #define ALWAYS_INLINE ATTR(always_inline)
    #define $$ ({ $$ })

    /**
     * The coding style uses the following regex to check for function names:
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
     * to avoid that false-positive.
     * Since this expression is unused, we place it in a $$ macro.
     *
     * Again, fixing the coding style by using one of its numerous bugs...
     **/

    #define IS_USED_BY_AUTOFREE(var) (void)(var)

    /**
     * When you define a AUTOFREE variable that isn't used by anything else
     * than the freeing function, it may appears as a "non-used" variable.
     *
     * This macro tell to do evaluate the expression causing it to be used.
     **/

    #define NEED_COMMA struct _

    /**
     * This macro is a purely aesthetic addition to force the use
     * of a semi-colon after another macro that end with it.
     *
     * This trick has been used in large codebases
     * such as the systemd project.
     *
     * We believe it is fine considering the epitech coding style
     * as this is not a garbage structure but a macro trick helping to make
     * cleaner macros.
     */

    #define STA_INL static inline ALWAYS_INLINE
    #define CLF_HEAD(name, ptr) STA_INL void name(void *ptr)
    #define CLF_BODY(type, func, ptr) if (*(type *)(ptr)) func(*(type *)ptr);

    #define CL_INTERN(n, t, f) CLF_HEAD(n, ptr) { CLF_BODY(t, f, ptr) }
    #define CLEANUP_FUNC(n, t, f) CL_INTERN(n, t, f) NEED_COMMA

    /**
     * These macros allow us to have a shorter definition
     * over auto-managed cleaning function that are been used
     * with __attribute__((cleanup, func)).
     *
     * While we could put regular declaration such as the following:
     *
     * static inline
     * USED void my_cleanup_func(void *ptr) {
     *     if (*ptr)
     *         clean_up(*ptr);
     * }
     *
     * It would be far longer to write every handler according to each scenario
     * due to function declaration not able to take arbitrary typed callback.
     *
     * If you believe this should be changed, please let us know
     * and we will rollback to it previous ugly hard-coded version.
     **/

CLEANUP_FUNC(free_stack, void *, free);
CLEANUP_FUNC(close_file, file_t *, fclose);
CLEANUP_FUNC(close_fd, int, close);

#endif /* !CLEAN_UP_H */
