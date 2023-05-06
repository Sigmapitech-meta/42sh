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

    #define PROMPT_BOX(item) BOLD BLUE "[" item BOLD BLUE "]" RESET
    #define USER_HOST GREEN "%s" RESET BOLD "@" CYAN "%s"
    #define PWD RESET BOLD "%s" BLUE

static const char *FORMAT_PROMPT = (
    BOLD BLUE "┌─" PROMPT_BOX(USER_HOST) " - " PROMPT_BOX(PWD) "\n"
    BOLD BLUE "└─" PROMPT_BOX(PURPLE "$") " "
);

#endif /* !PROMPT_H_ */
