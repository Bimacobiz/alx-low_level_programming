#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 *free_grid - frees a 2-D array
 *@height: height dimension of grid
 *@grid: 2d grid
 *Return nothing
 */
void free_grid(int **grid, int height)

{
	int i;

	for (i = 0; i < height; i++)

	{

		free(grid[i]);
	}

	free(grid);
}
