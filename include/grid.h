#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

#include <stdio.h> // for FILE

// Declare exported methods:
void gridInit(char* grid, int height, int width);
void gridWrite(const char* grid, const int height, const int width, FILE* file);

#endif // GRID_H_INCLUDED

