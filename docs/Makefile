##
## EPITECH PROJECT, 2023
## 42sh
## File description:
## Makefile
##

SPHINX_OPTS ?=
SPHINX_BUILD ?= sphinx-build
SCR_DIR := .
BUILD_DIR := .build

SPHINX = $(SPHINX_BUILD) -M $(1)
SPHINX += "$(SCR_DIR)" "$(BUILD_DIR)" $(SPHINX_OPTS) $(O)

help:
	@ $(call SPHINX, $@)

.PHONY: help Makefile

%: Makefile
	@ $(call SPHINX, $@)
