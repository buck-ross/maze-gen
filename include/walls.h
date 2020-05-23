#ifndef WALLS_H_INCLUDED
#define WALLS_H_INCLUDED

#include <stdlib.h>

#define ORIENT_VERTICAL (0)
#define ORIENT_HORIZONTAL (1)

struct wall {
	struct wall* next;
	unsigned char orient;
	int x;
	int y;
};

void pushWall(struct wall** walls, size_t* wallCount, int x, int y, unsigned char orient);
struct wall* popWall(struct wall** walls, size_t* wallCount);
void addWalls(char* grid, int height, int width, struct wall** walls, size_t* wallCount, int x, int y);

#endif // WALLS_H_INCLUDED

