#!/usr/bin/python3
"""Defines a function that measures the perimeter."""


def island_perimeter(grid):
    """The function returns the perimiter of an island.

    The grid is a representation of land by 1 and water by 0.

    Args:
        grid (list): List of ints that rep an island.
    Returns:
        The perimeter of the island that grid defines.
    """
    width = len(grid[0])
    height = len(grid)
    edges = 0
    size = 0

    for i in range(height):
        for j in range(width):
            if grid[i][j] == 1:
                size += 1
                if (j > 0 and grid[i][j - 1] == 1):
                    edges += 1
                if (i > 0 and grid[i - 1][j] == 1):
                    edges += 1
    return size * 4 - edges * 2
