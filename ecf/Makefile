.PHONY: all

objs := $(BIN_DIR)/sigint

all : $(objs)

$(BIN_DIR)/% : %.c
	@echo LD ++ $@
	@$(CC) $(CFLAGS) -o $@ $^
