ROOT_DIR := $(shell pwd)
BUILD_DIR := $(ROOT_DIR)/build
BIN_DIR := $(BUILD_DIR)/bin

SUB_DIR := $(dir $(shell find . -maxdepth 2 -name "Makefile" | grep -v "\./Makefile" | sort))

CC := gcc
C++ := g++
CFLAGS := -Wall -Werror -g
CPP := cpp
CCL := ccl
AS := as
LD := ld

export CC CPP CFLAGS C++ CCL AS LD
export BIN_DIR

.PHONY: all clean force

all : $(SUB_DIR)

$(SUB_DIR): force
	@mkdir -p $(BIN_DIR)
	@make -C $@

force:;

clean:
	@rm -rf $(BUILD_DIR)
