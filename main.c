#include <stdlib.h>
#include <stdio.h>
#include "grid.h"
#include "weave.h"

int main(int argc, char** argv) {
	// Check the arguments:
	if(argc != 4) {
		fprintf(stderr, "Error, please invoke as follows: `%s <filename> <height> <width>`.\n", argv[0]);
		return -1;
	}

	// Parse the dimensions:
	int height = atoi(argv[2]), width = atoi(argv[3]);
	if(height < 3 || width < 3 || height > 2501 || width > 2501 || height % 2 == 0 || width % 2 == 0) {
		fprintf(stderr, "Error, height & width must be valid positive odd integers 3 <= n <= 2501.\n");
		return -1;
	}

	// Open the output file:
	FILE* file = fopen(argv[1], "w");
	if(file == NULL) {
		fprintf(stderr, "Error, unable to open file '%s' for writing.\n", argv[1]);
		return -1;
	}

	// Create the grid:
	char maze[height][width];
	gridInit((char*)&maze[0][0], height, width);

	// Generate the maze:
	weaveGrid((char*)&maze[0][0], height, width);

	// Write the output data to the file:
	gridWrite((const char*)&maze[0][0], height, width, file);

	// Cleanup the program & exit:
	fclose(file);
	return 0;
}

