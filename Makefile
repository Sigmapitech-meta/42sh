##
## EPITECH PROJECT, 2023
## 42sh
## File description:
## Makefile
##

START_TIME := $(shell date +%s%3N)

# ↓ Remove builtin rules
.SUFFIXES:

# ↓ Config
CC := gcc
NAME = 42sh

CFLAGS := -W -Wall -Wextra
CFLAGS += -U_FORTIFY_SOURCE
CFLAGS += -iquote ./include

ifeq ($(FORCE_DEBUG),1)
    CFLAGS += -D DEBUG_MODE
endif

BUILD_DIR := .build

NAME_BATCH := batch_runner
NAME_DEBUG := debug
NAME_ANGRY := angry
TESTS := run_tests

# ↓ Clear all possible junk
VPATH :=

SRC :=
BSRC :=
TSRC :=

# ↓ Sources
VPATH += src
SRC += environment.c
SRC += main.c
SRC += prompt.c
SRC += shell.c

VPATH += src/base
SRC += str_split.c
SRC += eprintf.c
SRC += file_reader.c

VPATH += src/commands
SRC += builtins.c
SRC += debug_builtins.c
SRC += command_runner.c
SRC += change_directory.c
SRC += env_manipulation.c
SRC += location_builtins.c

VPATH += src/utils
SRC += get_line.c
SRC += parameters.c
SRC += path.c
SRC += status.c

VPATH += tests
TSRC := test_sentinel.c
TSRC += run_shell.c
TSRC += std_redirect.c

VPATH += tests/e2e
TSRC += test_setenv.c
TSRC += test_command_not_found.c

VPATH += tests/mocks
TSRC += mock_getline.c

VPATH += tests/integration
TSRC += test_autofree.c

VPATH += tests/integration/get_line
TSRC += test_get_line_fixed_data.c
TSRC += test_get_line_broken.c

# ↓ Batch runner sources

BSRC += $(filter-out %main.c, $(SRC))
BSRC += tests/run_shell.c

VPATH += batch
BSRC += batch_main.c

vpath %.c $(VPATH)

# ↓ `touch .fast` to force multi-threading
ifneq ($(shell find . -name ".fast"),)
    MAKEFLAGS += -j
endif

# ↓ Quiet
V ?=
ifeq ($(V), 1)
    $(info Verbose mode enabled)
    Q :=
else
    Q := @
endif

# ↓ Generators
OBJ := $(SRC:%.c=$(BUILD_DIR)/release/%.o)
DEBUG_OBJ := $(SRC:%.c=$(BUILD_DIR)/debug/%.o)
ANGRY_OBJ := $(SRC:%.c=$(BUILD_DIR)/angry/%.o)

TEST_OBJ := $(TSRC:%.c=$(BUILD_DIR)/tests/%.o)
TEST_OBJ += $(filter-out %main.o, $(SRC:%.c=$(BUILD_DIR)/tests/%.o))

BATCH_OBJ := $(BSRC:%.c=$(BUILD_DIR)/batch/%.o)

# ↓ Utils
ifneq ($(shell tput colors),0)
    C_RESET := \033[00m
    C_BOLD := \e[1m
    C_RED := \e[31m
    C_GREEN := \e[32m
    C_YELLOW := \e[33m
    C_BLUE := \e[34m
    C_PURPLE := \e[35m
    C_CYAN := \e[36m
endif

_SOLVE_COLORS = $(subst :r,$(C_RED), \
    $(subst :c,$(C_CYAN),            \
    $(subst :p,$(C_PURPLE),          \
    $(subst :y,$(C_YELLOW),          \
    $(subst :b,$(C_BLUE),            \
    $(subst :g,$(C_GREEN),           \
    $(subst *,$(C_BOLD),             \
    $(subst ~,$(C_RESET),            \
    $(addprefix $(call _UNQUOTE,$(1)),~)))))))))

_UNQUOTE = $(subst ",,$(subst ',,$(1)))##") ## <- Hack to make highlighter happy
_QUOTE = "$(strip $(1))"

COLORIZE = $(call _QUOTE, $(call _SOLVE_COLORS, $(1)))

CURRENT_TIME_MS = $(shell date +%s%3N)
TIME = $(shell expr $(call CURRENT_TIME_MS) - $(START_TIME))

HEADER := ":p"
LOG = @ echo -e $(call COLORIZE,$(2) ~$(TIME_BOX) $(HEADER)~ $(1)~)
TIME_BOX = "[ :b"$(call TIME)"~\t]"

# ↓ Rules
all: $(NAME)

.PHONY: all

$(NAME): $(OBJ)
	$Q $(CC) $(CFLAGS) $(LIBFLAGS) $(LDLIBS) -o $@ $^
	$(call LOG,":g$@")

$(BUILD_DIR)/release/%.o: HEADER += "release"
$(BUILD_DIR)/release/%.o: %.c
	@ mkdir -p $(dir $@)
	$Q $(CC) $(CFLAGS) -c $< -o $@
	$(call LOG, ":c" $(notdir $@))

$(NAME_DEBUG): CFLAGS += -g3 -D DEBUG_MODE
$(NAME_DEBUG): HEADER += "debug"
$(NAME_DEBUG): $(DEBUG_OBJ)
	$Q $(CC) $(CFLAGS) $(LIBFLAGS) $(LDLIBS) -o $@ $^
	$(call LOG,":g$@")

$(BUILD_DIR)/debug/%.o: %.c
	@ mkdir -p $(dir $@)
	$Q $(CC) $(CFLAGS) -c $< -o $@
	$(call LOG, ":c" $(notdir $@))

$(NAME_ANGRY): CFLAGS += -g3 -D DEBUG_MODE -fsanitize=address,leak,undefined
$(NAME_ANGRY): LDFLAGS += -lasan
$(NAME_ANGRY): HEADER += "angry"
$(NAME_ANGRY): $(ANGRY_OBJ)
	$Q $(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LDLIBS)
	$(call LOG,":g$@")

$(BUILD_DIR)/angry/%.o: %.c
	@ mkdir -p $(dir $@)
	$Q $(CC) $(CFLAGS) -c $< -o $@
	$(call LOG, ":c" $(notdir $@))

clean:
	$(eval REMOVED =                                               \
		$(shell                                                    \
			$(RM) -v $(OBJ) $(DEBUG_OBJ) $(ANGRY_OBJ) $(TEST_OBJ)  \
			| grep "removed" | cut -d ' ' -f 2))
	$(call LOG,                                                    \
		$(if $(REMOVED), "removed:c" $(REMOVED), "no file removed."))

fclean:
	$(call LOG,                                                       \
		$(if $(shell find . -type d -name $(BUILD_DIR)),              \
			":r-:c $(BUILD_DIR)~",                                    \
			"no build dir to remove."))
	@ $(RM) -r $(BUILD_DIR)
	$(eval REMOVED =                                                  \
		$(shell $(RM) -v $(NAME) $(NAME_DEBUG) $(NAME_ANGRY) $(TESTS) \
			| grep "removed" | cut -d ' ' -f 2))
	$(call LOG,                                                       \
		$(if $(REMOVED),"removed:g" $(REMOVED), "no binary to remove."))

.PHONY: clean fclean

both: all debug

re: fclean
	+ $Q $(call RECURSE, both)

.PHONY: re both

$(BUILD_DIR)/tests/%.o: %.c
	$Q mkdir -p $(dir $@)
	$Q $(CC) $(CFLAGS) -c $< -o $@
	$(call LOG, ":c" $(notdir $@))

$(TESTS): CFLAGS += -g3 --coverage
$(TESTS): CFLAGS += -iquote tests/include
$(TESTS): LDLIBS += -lcriterion
$(TESTS): LDLIBS += -Wl,--wrap=getline
$(TESTS): LDFLAGS += -fprofile-arcs -ftest-coverage
$(TESTS): $(TEST_OBJ)
	$Q $(CC) -o $@ $^ $(CFLAGS) $(LDLIBS) $(LDFLAGS)
	$(call LOG,":g$@")

tests_run: $(TESTS)
	@ ./$(TESTS) -OP:F --full-stats

.PHONY: tests_run

cov: tests_run
	$(call CHECK_CMD, gcovr)
	$Q $(call CHECK_CMD, gcovr)
	$Q gcovr . --exclude tests

.PHONY: cov

batch: $(NAME_BATCH)

.PHONY: batch

$(BUILD_DIR)/batch/%.o: HEADER += "batch"
$(BUILD_DIR)/batch/%.o: %.c
	@ mkdir -p $(dir $@)
	$Q $(CC) $(CFLAGS) -c $< -o $@
	$(call LOG, ":c" $(notdir $@))

$(NAME_BATCH): CFLAGS += -iquote tests/include
$(NAME_BATCH): CFLAGS += -D DEBUG_MODE
$(NAME_BATCH): $(BATCH_OBJ)
	$Q $(CC) -o $@ $^ $(CFLAGS) $(LDLIBS) $(LDFLAGS)
	$(call LOG,":g$@")

# ↓ Utils
RECURSE = $(MAKE) $(1) --no-print-directory START_TIME=$(START_TIME)

# ↓ file & rules guard
SENTINEL = $(error Missing $(if $(findstring .,$(1)),file,rule) $(1))

%:
	$(call SENTINEL, $@)

undefine %.c

%.c:
	$(call SENTINEL, $@)

# ↓ User override

ifneq ($(shell find . -name override.mk),)
-include override.mk
endif
