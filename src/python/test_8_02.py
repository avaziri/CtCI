# Copyright 2017 Andrew Vaziri
# CtCI Question #8.2
# |||Prompt|||
# Imagine a robot sitting on the upper left corner of a grid with c columns and r rows. The robot
# can only move in two directions, right and down. Some cells are "off limtis" such that the robot
# can not step on them. Find an algorithm to allow the robot to find a path from upper left to
# bottom right.
# |||Questions I might ask|||
# Q: Do I return if there is a path as a true/false? Or do I return the series of moves? A: moves
# Q: Is there guaranteed to be a path? A: No, return none if there is no path
# Q: Can I assume I have the whole map in advance, in other words I don't have to move to explore?
#    A: Yes you have the whole map up front
# Q: Can I treat the edges of the map as "off limits"? A: yes
# Q: Do you want the shortest path? A: No, not necessarily.
# Q: Can I assume the grid is at least 1x1? A: Sure
import pytest
import numpy as np
import time
# |||Implementation 1|||
# In general, for path planning problems we might want to use BFS to find an optimal path. However
# given the rules of this world all paths must be the same length (r-1) moves down and (c-1) moves
# to the right. While BFS will expand every node before the goal, DFS may not have to. Since both
# provide equally good results lets stick with DFS since it will be faster.
# be even faster we could use 
# |||Time Complexity|||
# In the worst case DFS would have to expand the upper right triangle of nodes O(r*c/2) = O(r*c)
# |||Space Complexity|||
# This implementation is keeping partial lists of moves as the search continues. The depth of the
# search may be O(r+c) each of which have a partially constructed list of moves which grows from
# size zero to O(r+c), these two things together then have a space complexity of O((r+c)^2)

# Assume grid is a list of rows lists. An element is 1 when "off-limits".
def find_path(grid):
    if (grid == None or len(grid) == 0 or len(grid[0])==0):
        return None
    return recur_find_path((0,0), grid)

def recur_find_path(loc, grid, list_of_moves=[], visited=set()):
    print("\nThe current location is {} with moves series: {}".format(loc, list_of_moves))
    # Check if current location is invalid
    if ((loc[0] >= len(grid)) or (loc[1] >= len(grid[0])) or grid[loc[0]][loc[1]]):
        return None
    # Check if current location is the goal
    if ((loc[0] == len(grid)-1) and (loc[1] >= len(grid[0])-1)):
        return list_of_moves
    # Prepare inputs needed for recursive calls
    # Make copies so we dont mutate the input
    right_moves = list_of_moves.copy()
    right_moves.append('right')
    down_moves = list_of_moves.copy()
    down_moves.append('down')
    right_loc = tuple((loc[0],loc[1]+1))
    down_loc = tuple((loc[0]+1,loc[1]))
    # Try moving from current location
    if not right_loc in visited:
        visited.update(right_loc)
        right_result = recur_find_path(right_loc, grid, right_moves)
        if right_result:
          return right_result
    if not down_loc in visited:
        visited.update(down_loc)
        down_result = recur_find_path(down_loc, grid, down_moves)
        if down_result:
          return down_result
    # If there is no path from right or left return None
    return None

# ----Tests and helper code----
def test_all_clear():
    grid = [[0, 0, 0, 0],
            [0, 0, 0, 0],
            [0, 0, 0, 0],
            [0, 0, 0, 0]]
    path = find_path(grid)
    print("\nA path to the goal is:{}!".format(path))
    assert path

def test_worst_case():
    grid = [[0, 0, 0, 0],
            [0, 0, 0, 0],
            [0, 1, 1, 1],
            [0, 0, 0, 0]]
    path = find_path(grid)
    print("\nA path to the goal is:{}!".format(path))
    assert path

def test_no_path():
    grid = [[0, 0, 0, 1],
            [0, 0, 1, 0],
            [0, 1, 0, 0],
            [1, 0, 0, 0]]
    path = find_path(grid)
    print("\nA path to the goal is:{}!".format(path))
    assert not path

def test_off_limit_start():
    grid = [[1, 0, 0, 0],
            [0, 0, 0, 0],
            [0, 0, 0, 0],
            [0, 0, 0, 0]]
    path = find_path(grid)
    print("\nA path to the goal is:{}!".format(path))
    assert not path

def test_off_limit_end(): grid = [[0, 0, 0, 0],
            [0, 0, 0, 0],
            [0, 0, 0, 0],
            [0, 0, 0, 1]]
    path = find_path(grid)
    print("\nA path to the goal is:{}!".format(path))
    assert not path

def test_wider_than_long():
    grid = [[0, 0, 0, 0],
            [0, 0, 0, 0],
            [0, 0, 0, 0]]
    path = find_path(grid)
    print("\nA path to the goal is:{}!".format(path))
    assert path
    
def test_longer_than_wide():
    grid = [[0, 0, 0],
            [0, 0, 0],
            [0, 0, 0],
            [0, 0, 0]]
    path = find_path(grid)
    print("\nA path to the goal is:{}!".format(path))
    assert path
    
def test_goal_is_start():
    grid = [[0]]
    path = find_path(grid)
    print("\nA path to the goal is:{}!".format(path))
    assert (path != None)

def test_3x3():
    grid = [[0, 0 , 0],
            [0, 0 , 0],
            [0, 0 , 0]]
    path = find_path(grid)
    print("\nA path to the goal is:{}!".format(path))
    assert path

def test_2x2():
    grid = [[0, 0],
            [0, 0]]
    path = find_path(grid)
    print("\nA path to the goal is:{}!".format(path))
    assert path

def test_none_grid():
    grid = None
    path = find_path(grid)
    print("\nA path to the goal is:{}!".format(path))
    assert not path

def test_no_rows_grid():
    grid = [[]]
    path = find_path(grid)
    print("\nA path to the goal is:{}!".format(path))
    assert not path

def test_no_cols_grid():
    grid = []
    path = find_path(grid)
    print("\nA path to the goal is:{}!".format(path))
    assert not path

def test_large_grid():
    grid = np.zeros((400,400)).tolist()
    start_time = time.time()
    path = find_path(grid)
    end_time = time.time()
    delta_time = end_time - start_time
    print("\nA path to the goal is:{}!".format(path))
    print("Solution found in {} seconds.".format(delta_time))
    assert path
