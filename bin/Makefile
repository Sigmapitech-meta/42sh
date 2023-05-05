##
## EPITECH PROJECT, 2023
## 42sh
## File description:
## Makefile
##

BINS := div_zero
BINS += double_free
BINS += free_invalid_pointer
BINS += segfault
BINS += segfault_core_dump

SRC := $(BINS:%=src/%.c)

CFLAGS := -U_FORTIFY_SOURCE
CFLAGS += -O0

all: $(BINS)

fclean:
	$(RM) $(BINS)

.PHONY: all fclean

%:
	$(CC) $(CFLAGS) src/$@.c -o $@
