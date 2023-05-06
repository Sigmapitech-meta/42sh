##
## EPITECH PROJECT, 2023
## 42sh
## File description:
## Makefile
##

BINS := double_free
BINS += free_invalid_pointer
BINS += segfault
BINS += segfault_core_dump
BINS += floating_exeption
BINS += floating_exeption_core_dump

SRC := $(BINS:%=src/%.c)

CFLAGS := -U_FORTIFY_SOURCE
CFLAGS += -O0

all: $(BINS)

fclean:
	$(RM) $(BINS)

re: fclean all

.PHONY: all fclean re

%:
	$(CC) $(CFLAGS) src/$@.c -o $@
