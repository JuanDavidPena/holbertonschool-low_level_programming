#!/usr/bin/python3
"""
    Technical interview preparation:
"""


def island_perimeter(grid):
    """
    returns the perimeter of the island described in grid:
    grid is a list of list of integers:
        0 represents a water zone
        1 represents a land zone
        One cell is a square with side length 1
        Grid cells are connected horizontally/vertically (not diagonally).
        Grid is rectangular, width and height don’t exceed 100
    Grid is completely surrounded by water, and there is one
    island (or nothing).
    The island doesn’t have “lakes” (water inside that isn’t
    connected to the water around the island).
    """
    visit = set()

    def dfs(i, j):
        """
        Recursive Depth first search algorithm
        """
        if i >= len(grid) or j >= len(grid[0]):
            return 1
        if i < 0 or j < 0 or grid[i][j] == 0:
            return 1
        if (i, j) in visit:
            return 0

        visit.add((i, j))
        perim = dfs(i, j + 1)
        perim += dfs(i + 1, j)
        perim += dfs(i, j - 1)
        perim += dfs(i - 1, j)
        return perim

    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:
                return dfs(i, j)
    return 0
