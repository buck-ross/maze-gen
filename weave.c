#include <stdlib.h>
#include "walls.h"
#include "weave.h"

// Export a method to weave a maze into a pre-defined grid:
void weaveGrid(char* grid, int height, int width) {
	// Declare a list to store the walls:
	struct wall* walls = NULL;
	size_t wallCount = 0;

	// Select a random starting position:
	int x1 = (rand() % ((height - 1) / 2)) * 2 + 1;
	int y1 = (rand() % ((width - 1) / 2)) * 2 + 1;

	// Visit the initial position, mark it visited, & add its walls to the wall list:
	grid[x1 * width + y1] = 'p'; // Declare a path
	addWalls(grid, height, width, &walls, &wallCount, x1, y1);

	// Iterate through every wall in the grid:
	while(wallCount != 0) {
		// Select a random wall from the list of walls:
		struct wall* randWall = popWall(&walls, &wallCount);
		
		// Check the wall's orientation:
		switch(randWall->orient) {
			case ORIENT_VERTICAL:
				// Check that both sides of the wall have not been visited:
				if(grid[(randWall->x - 1) * width + randWall->y] == 'p' && grid[(randWall->x + 1) * width + randWall->y] == 'w') {
					grid[randWall->x * width + randWall->y] = 'p';
					grid[(randWall->x + 1) * width + randWall->y] = 'p';
					addWalls(grid, height, width, &walls, &wallCount, randWall->x + 1, randWall->y);
				} else if(grid[(randWall->x + 1) * width + randWall->y] == 'p' && grid[(randWall->x - 1) * width + randWall->y] == 'w') {
					grid[randWall->x * width + randWall->y] = 'p';
					grid[(randWall->x - 1) * width + randWall->y] = 'p';
					addWalls(grid, height, width, &walls, &wallCount, randWall->x - 1, randWall->y);
				}
				break;
			default:
				// Check that both sides of the wall have not been visited:
				if(grid[randWall->x * width + randWall->y - 1] == 'p' && grid[randWall->x * width + randWall->y + 1] == 'w') {
					grid[randWall->x * width + randWall->y] = 'p';
					grid[randWall->x * width + randWall->y + 1] = 'p';
					addWalls(grid, height, width, &walls, &wallCount, randWall->x, randWall->y + 1);
				} else if(grid[randWall->x * width + randWall->y + 1] == 'p' && grid[randWall->x * width + randWall->y - 1] == 'w') {
					grid[randWall->x * width + randWall->y] = 'p';
					grid[randWall->x * width + randWall->y - 1] = 'p';
					addWalls(grid, height, width, &walls, &wallCount, randWall->x, randWall->y - 1);
				}
		}

		// Free the wall:
		free(randWall);
	}
}

