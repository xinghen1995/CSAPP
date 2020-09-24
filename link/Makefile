.PHONY: all

objs := $(BIN_DIR)/prog

all : $(objs)

$(BIN_DIR)/prog : main.c sum.c
	$(CPP) main.c $(BIN_DIR)/main.i
	$(CCL) $(BIN_DIR)/main.i -o $(BIN_DIR)/main.s
	$(AS) -o $(BIN_DIR)/main.o $(BIN_DIR)/main.s
	$(LD) -o $@ $(BIN_DIR)/main.o sum.o

