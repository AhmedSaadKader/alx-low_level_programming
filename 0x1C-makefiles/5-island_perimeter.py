#!/usr/bin/python3
"""Contains function island_perimeter to return
the perimeter of the island described in grid
"""


def island_perimeter(grid):
    """Returns the perimeter of the island described
    in grid

    Args:
        grid (list): list of list of integers that describe an island
    """
    rows = len(grid)
    cols = len(grid[0])
    perimeter = 0
    island_start = (0, 0)
    island_end = (0, 0)
    for l in range(rows):
        for i in range(cols):
            if grid[l][i] == 1:
                island_start = (l, i)
                break
        if island_start != (0, 0):
            break
    for l in range(rows - 1, -1, -1):
        for i in range(cols - 1, -1, -1):
            if grid[l][i] == 1:
                island_end = (l, i)
                break
        if island_end != (0, 0):
            break
    land_slots_x = island_end[0] - island_start[0]
    land_slots_y = island_end[1] - island_start[1]
    land_slots = land_slots_x + land_slots_y + 1
    perimeter = land_slots * 2 + 2
    return perimeter
