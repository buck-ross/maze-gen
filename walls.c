#include <stdlib.h>
#include "walls.h"

// Export a method to push a wall to the list:
void pushWall(struct wall** walls, size_t* wallCount, int x, int y, unsigned char orient) {
	struct wall* tmp = *walls;
	*walls = malloc(sizeof(struct wall));
	(*walls)->next = tmp;
	(*walls)->orient = orient;
	(*walls)->x = x;
	(*walls)->y = y;
	++(*wallCount);
}

// Export a method to push a wall to the list:
struct wall* popWall(struct wall** walls, size_t* wallCount) {
	// Select a random index:
	const int select = rand() % *wallCount;

	// Iterate through the list until the index is reached:
	struct wall** index = walls;
	for(int i = 0; i < select; ++i)
		index = &((*index)->next);

	// Pop the selected wall out of the list & return it:
	struct wall* tmp = *index;
	*index = (*index)->next;
	tmp->next = NULL;
	--(*wallCount);
	return tmp;
}

// Export a method to add all walls surrounding a particular position to a walls list:
void addWalls(char* grid, int height, int width, struct wall** walls, size_t* wallCount, int x, int y) {
	// Handle the wall above:
	if(x - 2 > 0 && grid[(x - 2) * width + y] == 'w')
		pushWall(walls, wallCount, x - 1, y, ORIENT_VERTICAL);

	// Handle the wall below:
	if(x + 2 < height && grid[(x + 2) * width + y] == 'w')
		pushWall(walls, wallCount, x + 1, y, ORIENT_VERTICAL);

	// Handle the left wall:
	if(y - 2 > 0 && grid[x * width + y - 2] == 'w')
		pushWall(walls, wallCount, x, y - 1, ORIENT_HORIZONTAL);

	// Handle the right wall:
	if(y + 2 < width && grid[x * width + y + 2] == 'w')
		pushWall(walls, wallCount, x, y + 1, ORIENT_HORIZONTAL);
}

