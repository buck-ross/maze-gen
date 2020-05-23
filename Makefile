CC=gcc
CFLAGS=-Iinclude -Wall -Wextra -Wwrite-strings
LFLAGS=
MAZE_DIMENSIONS=51 51

.PHONY: all

all: libmaze.so

maze-gen: main.o grid.o weave.o walls.o
	$(CC) $(LFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

main.o: include/grid.h include/weave.h
grid.o: include/grid.h
weave.o: include/weave.h include/walls.h
walls.o: include/walls.h

# Define targets for building the static library:

maze.xpm: maze-gen
	./maze-gen maze.xpm $(MAZE_DIMENSIONS)

libmaze.so: maze.c maze.xpm include/maze.h
	$(CC) -shared -o libmaze.so -fpic $(CFLAGS) maze.c


