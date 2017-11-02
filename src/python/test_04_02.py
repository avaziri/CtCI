# Copyright 2017 Andrew Vaziri
# CtCI Question #4.2
# |||Prompt|||
# Given a sorted  (increasing order) array with unique integer elements
# write an algorithm  to create a binary search tree with minimal height.
# |||Questions I might ask|||
# Q: Minimum as measured from the root to the most distant child? A: Yes
# Q: Do I have to be perfectly minimal? I imagine tie-breaking which node
#    you choose to be added to the tree when the array is of an even length
#    might eventually cause some sub-optimality. A: Do you best, start wtih
#    an arbitrary tie breaking mechanism and optimize if we have time

import pytest

# |||Implementation 1|||
# I could use recursion. I take a list, split it down the middle and make it
# into two lists and a parent node. This process continues until the lists have
# no elements.
# |||Time Complexity|||
# |||Space Complexity|||

def sorted_list_to_binary_tree(input):
    if (len(input)==0):
        return
    if (len(input)==1):
        return (input[0])
    #if (len(input)==2):
    #    return (input[0], input[1])
    else:
        pivot_index = len(input)//2 # Integer Division
        left_list = input[0:(pivot_index-1)]
        right_list = input[(pivot_index+1):-1]
        return (input[pivot_index],
                sorted_list_to_binary_tree(left_list),
                sorted_list_to_binary_tree(right_list))

def print_binary_tree(input):
    if (not input):
        return
    if (len(input)==0):
        pass
    elif (len(input)==1):
        print(input[0])
    else:
        print_binary_tree(input[1])
        print(input[0])
        print_binary_tree(input[2])
    
def test_simple_array():
    input = [1, 2, 3, 4, 5, 6, 7, 8]
    tree = sorted_list_to_binary_tree(input)
    print_binary_tree(tree)
    assert tree


