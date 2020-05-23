CC=gcc
CFLAGS=-Iinclude -Wall -Wextra -Wwrite-strings
LFLAGS=

.PHONY: all

all: mazeGen

mazeGen: main.o grid.o
	$(CC) $(LFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

main.o: include/grid.h
grid.o: include/grid.h

