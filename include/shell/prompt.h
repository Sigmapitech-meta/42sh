/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** prompt.h
*/

#ifndef PROMPT_H_
    #define PROMPT_H_

    #define HOSTNAME_MAX_LEN 64

    #define C_BOLD "\e[1m"
    #define C_GREEN "\e[32m"
    #define C_BLUE "\e[34m"
    #define C_PURPLE "\e[35m"
    #define C_CYAN "\e[36m"
    #define RESET "\033[0m"

    #define _PROMPT_BOX(item) C_BOLD C_BLUE "[" item C_BOLD C_BLUE "]" RESET
    #define _USER_HOST C_GREEN "%s" RESET C_BOLD "@" C_CYAN "%s"
    #define _CWD RESET C_BOLD "%s" C_BLUE

static const char *FORMAT_PROMPT = (
    C_BOLD C_BLUE "┌─" _PROMPT_BOX(_USER_HOST) " - " _PROMPT_BOX(_CWD) "\n"
    C_BOLD C_BLUE "└─" _PROMPT_BOX(C_PURPLE "$") " "
);

#endif /* !PROMPT_H_ */
