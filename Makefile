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
NAME_AFL := $(NAME)_afl

TESTS := run_tests

BINS := $(NAME) $(NAME_BATCH)
BINS += $(NAME_DEBUG) $(NAME_ANGRY)
BINS += $(NAME_AFL) $(TESTS)

# ↓ Sources
VPATH += src
SRC += environment.c
SRC += main.c
SRC += prompt.c
SRC += shell.c

VPATH += src/base
SRC += str_split.c
SRC += str_replace.c
SRC += file_reader.c

VPATH += src/list
SRC += list_append.c
SRC += list_get.c
SRC += list_remove.c

VPATH += src/commands
SRC += builtins.c
SRC += command_runner.c
SRC += change_directory.c
SRC += env_manipulation.c
SRC += location_builtins.c

VPATH += src/utils
SRC += parameters.c
SRC += path.c
SRC += status.c

VPATH += tests
TSRC := test_sentinel.c
TSRC += run_shell.c
TSRC += std_redirect.c

VPATH += tests/commands
TSRC += test_cd.c
TSRC += test_command_not_found.c
TSRC += test_env.c
TSRC += test_exit.c
TSRC += test_ls.c
TSRC += test_setenv.c
TSRC += test_setenv.c
TSRC += test_setenv_invalid_names.c
TSRC += test_unsetenv.c
TSRC += test_where.c
TSRC += test_which.c

VPATH += tests/mocks
TSRC += mock_getline.c
TSRC += mock_malloc.c
TSRC += mock_read.c
TSRC += mock_stat.c

TSRC += mock_gethostname.c
TSRC += mock_getcwd.c
TSRC += mock_getenv.c

VPATH += tests/integration
TSRC += test_autofree.c
TSRC += test_autoclose.c
TSRC += test_list_structure.c
TSRC += test_file_read.c

VPATH += tests/unit
TSRC += test_str_count_tok.c
TSRC += test_str_split.c
TSRC += test_str_trans.c
TSRC += test_str_replace.c
TSRC += test_prompt.c
TSRC += test_status_show.c

VPATH += tests/integration/get_line
TSRC += test_get_line_fixed_data.c
TSRC += test_get_line_broken.c

# ↓ Debug only sources

DSRC := $(SRC)
DSRC += debug_colorize.c
DSRC += debug_builtins.c

# ↓ Batch runner sources
BSRC += $(filter-out %main.c, $(DSRC))
BSRC += tests/run_shell.c

VPATH += batch
BSRC += batch_main.c

ASRC := $(SRC)
ASRC += mock_execve.c

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

DEBUG_OBJ := $(DSRC:%.c=$(BUILD_DIR)/debug/%.o)
ANGRY_OBJ := $(DSRC:%.c=$(BUILD_DIR)/angry/%.o)

TEST_OBJ := $(TSRC:%.c=$(BUILD_DIR)/tests/%.o)
TEST_OBJ += $(filter-out %main.o, $(SRC:%.c=$(BUILD_DIR)/tests/%.o))

BATCH_OBJ := $(BSRC:%.c=$(BUILD_DIR)/batch/%.o)
AFL_OBJ := $(ASRC:%.c=$(BUILD_DIR)/afl/%.o)

OBJS := $(OBJ) $(AFL_OBJ)
OBJS += $(DEBUG_OBJ) $(ANGRY_OBJ)
OBJS += $(TEST_OBJ)

ALL_OBJS := $(OBJ)
ALL_OBJS += $(DEBUG_OBJ) $(ANGRY_OBJ)
ALL_OBJS += $(TEST_OBJ) $(AFL_OBJ)

CMD_NOT_FOUND = $(error $(strip $(1)) is required for this rule)
CHECK_CMD = $(if $(shell command -v $(1)),, $(call CMD_NOT_FOUND, $(1)))

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

$(NAME_ANGRY): CFLAGS += -D DEBUG_MODE
$(NAME_ANGRY): CFLAGS += -g3 -fsanitize=address,leak,undefined
$(NAME_ANGRY): LDFLAGS += -lasan
$(NAME_ANGRY): HEADER += "angry"
$(NAME_ANGRY): $(ANGRY_OBJ)
	$Q $(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LDLIBS)
	$(call LOG,":g$@")

$(BUILD_DIR)/angry/%.o: %.c
	@ mkdir -p $(dir $@)
	$Q $(CC) $(CFLAGS) -c $< -o $@
	$(call LOG, ":c" $(notdir $@))

afl: $(NAME_AFL)

.PHONY: afl

$(NAME_AFL): CC := afl-gcc
$(NAME_AFL): CFLAGS += -g3 -march=native -fsanitize=address
$(NAME_AFL): CFLAGS += -iquote tests/include
$(NAME_AFL): CFLAGS += -Wl,--wrap=execve
$(NAME_AFL): HEADER += "AFL"
$(NAME_AFL): $(AFL_OBJ)
	$Q AFL_USE_ASAN=1 $(CC) $(CFLAGS) $(LIBFLAGS) $(LDLIBS) -o $@ $^
	$(call LOG,":g$@")

_afl_run_cmd_%:
	+$Q kitty \
        -o initial_window_width=680   \
        -o initial_window_height=520  \
        -o font_size=10               \
        -e afl-fuzz                   \
            -o tests/generated        \
            -m none                   \
            -S $@                     \
		    -i tests/fixtures/input   \
		    -x tests/fixtures/tokens  \
		    -- ./42sh_afl

.PHONY: _afl_run_cmd

_afl_run: _afl_run_cmd_1 _afl_run_cmd_2

afl_run: $(NAME_AFL)
	@ afl-fuzz \
		-o tests/generated        \
		-m none                   \
		-i tests/fixtures/input   \
		-x tests/fixtures/tokens  \
		-- ./42sh_afl

afl_run_dual: $(NAME_AFL)
	@ $(call CHECK_CMD, kitty)

	echo core | sudo tee /proc/sys/kernel/core_pattern
	+$Q kitty --single-instance \
        -o initial_window_width=80  \
        -o initial_window_height=80 \
		-e $(MAKE) -j 2 _afl_run

.PHONY: afl_run afl_run_dual _afl_run

$(BUILD_DIR)/afl/%.o: %.c
	@ mkdir -p $(dir $@)
	$Q $(CC) $(CFLAGS) -c $< -o $@
	$(call LOG, ":c" $(notdir $@))

clean:
	$(eval REMOVED =                                               \
		$(shell                                                    \
			$(RM) -v $(ALL_OBJS)                                   \
			| grep "removed" | cut -d ' ' -f 2))
	$(call LOG,                                                    \
		$(if $(REMOVED), "removed:c" $(REMOVED), "no file removed."))

fclean:
	$(call LOG,                                                    \
		$(if $(shell find . -type d -name $(BUILD_DIR)),           \
			":r-:c $(BUILD_DIR)~",                                 \
			"no build dir to remove."))
	@ $(RM) -r $(BUILD_DIR)
	$(eval REMOVED =                                               \
		$(shell $(RM) -v $(BINS)                                   \
			| grep "removed" | cut -d ' ' -f 2))
	$(call LOG,                                                    \
		$(if $(REMOVED),"removed:g" $(REMOVED), "no binary to remove."))
	@ $(MAKE) -sC bin fclean

.PHONY: clean fclean

both: all debug

re: fclean
	+ $Q $(call RECURSE, both)

.PHONY: re both

$(BUILD_DIR)/tests/%.o: %.c
	$Q mkdir -p $(dir $@)
	$Q $(CC) $(CFLAGS) -c $< -o $@
	$(call LOG,":c" $(notdir $@))

_TEST_WRAPS := --wrap=getline
_TEST_WRAPS += --wrap=stat
_TEST_WRAPS += --wrap=read
_TEST_WRAPS += --wrap=malloc
_TEST_WRAPS += --wrap=getenv
_TEST_WRAPS += --wrap=getcwd
_TEST_WRAPS += --wrap=gethostname

_COMMA := ,
SPACE := $(subst a, ,a)

$(TESTS): CFLAGS += -g3 --coverage
$(TESTS): CFLAGS += -iquote tests/include
$(TESTS): LDLIBS += -lcriterion
$(TESTS): LDLIBS += -Wl,$(subst $(SPACE),$(_COMMA),$(_TEST_WRAPS))
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
	$(call LOG,":c" $(notdir $@))

$(NAME_BATCH): CFLAGS += -iquote tests/include
$(NAME_BATCH): CFLAGS += -D DEBUG_MODE
$(NAME_BATCH): $(BATCH_OBJ)
	$Q $(CC) -o $@ $^ $(CFLAGS) $(LDLIBS) $(LDFLAGS)
	$(call LOG,":g$@")

bundle: $(BINS)
	@+ $(MAKE) -sC bin
	$(call LOG,":g$@")

.PHONY: bundle

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
