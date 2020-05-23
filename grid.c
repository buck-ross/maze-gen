#include <stdio.h>
#include <string.h>

// Declare constant variables to store the XPM header:
static const char* XPMHeader = "/* XPM */\nstatic const char* xpmData[] = {\n";
static const char* XPMColors = "\"p\tc #FFFFFF\",\n\"w\tc #000000\",\n";

// Export a method to initialize the grid with a set of squares & walls:
void gridInit(char* grid, int height, int width) {
	// Fill in the grid with walls:
	for(int i = 0; i < height; ++i)
		for(int j = 0; j < width; ++j)
			// Declare a wall:
			grid[i * width + j] = 'w';
	
	// Define the grid's starting & ending points:
	grid[1] = 'p';
	grid[height * width - 2] = 'p';
}

// Export a method to write the provided grid out to a file:
void gridWrite(const char* grid, const int height, const int width, FILE* file) {
	// Write the XPM header info to the file:
	fwrite(XPMHeader, 1, strlen(XPMHeader), file);
	char headerBuff[17];
	int len = sprintf(&headerBuff[0], "\"%d %d 2 1\",\n", width, height);
	fwrite(&headerBuff[0], 1, len, file);
	fwrite(XPMColors, 1, strlen(XPMColors), file);

	// Write each row to the file:
	char rowBuff[width + 6];
	rowBuff[0] = '\"';
	rowBuff[width + 1] = '\"';
	rowBuff[width + 2] = ',';
	rowBuff[width + 3] = '\n';
	for(int i = 0; i < height - 1; ++i) {
		strncpy(&rowBuff[1], &grid[i * width], width);
		fwrite(&rowBuff[0], 1, width + 4, file);
	}

	// Write the last line:
	rowBuff[width + 2] = '}';
	rowBuff[width + 3] = ';';
	rowBuff[width + 4] = '\n';
	rowBuff[width + 5] = '\n';
	strncpy(&rowBuff[1], &grid[(height - 1) * width], width);
	fwrite(&rowBuff[0], 1, width + 6, file);
}

