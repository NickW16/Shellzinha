CC = cc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2 -g
LDLIBS = -lreadline
SRC = src/main.c src/parse.c src/exec.c
BIN = shellzinha

all: $(BIN)

$(BIN): $(SRC) src/shell.h
	$(CC) $(CFLAGS) -o $@ $(SRC) $(LDLIBS)

clean: 
	rm -f $(BIN)

.PHONY: all clean
