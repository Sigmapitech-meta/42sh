/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** prompt.h
*/

#ifndef PROMPT_H_
    #define PROMPT_H_

    #include "utils/colors.h"

    #define HOSTNAME_MAX_LEN 64

    #define _PROMPT_BOX(item) BOLD BLUE "[" item BOLD BLUE "]" RESET
    #define _USER_HOST GREEN "%s" RESET BOLD "@" CYAN "%s"
    #define _CWD RESET BOLD "%s" BLUE

static const char *FORMAT_PROMPT = (
    BOLD BLUE "┌─" _PROMPT_BOX(_USER_HOST) " - " _PROMPT_BOX(_CWD) "\n"
    BOLD BLUE "└─" _PROMPT_BOX(PURPLE "$") " "
);

#endif /* !PROMPT_H_ */
