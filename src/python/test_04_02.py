# Copyright 2017 Andrew Vaziri
# CtCI Question #4.2
# |||Prompt|||
# Given a sorted  (increasing order) array with unique integer elements
# write an algorithm  to create a binary search tree with minimal height.
# |||Questions I might ask|||
# Q: Minimum as measured from the root to the most distant child? A: Yes
# Q: Do I have to be perfectly minimal? I imagine tie-breaking which node
#    you choose to be added to the tree when the array is of an even length
#    might eventually cause some sub-optimality. A: Do your best, start wtih
#    an arbitrary tie breaking mechanism and optimize if we have time

import pytest
import math, random

# |||Implementation 1|||
# I could use recursion. I take a list, split it down the middle and make it
# into two lists and a parent node. This process continues until the lists
# have no elements.
# I chose to just use a tuple to represent a node. The 0'th element is the
# node's value, the 1'st element is the left child, and the 2'nd element is
# the right child. This was a really bad idea, and makes the code very hard
# to read. It also causes lot of type confusion, as most tuples have a length
# except those which are leaves do not. I should have used a named tuple or
# dictionary or made my own node class.
# |||Time Complexity|||
# Every data has to be touched by a constant number of operations O(N)
# |||Space Complexity|||
# The original list and the tree are both O(N) in space

def sorted_list_to_binary_tree(input):
    if (len(input)==0):
        return
    if (len(input)==1):
        print("Leaf: {}".format(input[0]))
        return (input[0])
    else:
        # Cut the list in half at the pivot index, which becomes the parent
        pivot_index = (len(input))//2 # Integer Division
        left_list = input[0:(pivot_index)]
        right_list = input[(pivot_index+1):]
        print("Parent: {} \n   left: {}\n   right: {}".format(
            input[pivot_index],
            left_list,
            right_list))
    return (input[pivot_index],
            sorted_list_to_binary_tree(left_list),
            sorted_list_to_binary_tree(right_list))
    
# ----Tests and helper code----

def tree_to_in_order_list(input, list=[]):
    # If None, add nothing to list
    if (input == None):
        return
    # Try to get the length, but if it is a leaf node that will cause a
    # TypeError which should be caught.
    try:
        # If it does have a length, append value, and recurse on children
        dont_care = len(input)
        tree_to_in_order_list(input[1], list)
        list.append(input[0])
        tree_to_in_order_list(input[2], list)
    except TypeError:
        # If it does not have a length append value
        list.append(input)

def find_maximum_depth(input):
    if (input == None):
        return 0
    try:
        # If it has a length recurse 
        dont_care = len(input)
        return 1+max(find_maximum_depth(input[1]), find_maximum_depth(input[2]))
    except TypeError:
        # If it does not have a length, meaning it is a leaf
        return 0

def test_simple_array():
    input = [1, 2, 3, 4, 5, 6, 7, 8]
    tree = sorted_list_to_binary_tree(input)
    # Recreate input list, confirm that it is the same
    recreated_input = []
    tree_to_in_order_list(tree, recreated_input)
    print(recreated_input)
    assert input == recreated_input
    # Make sure the tree was as compact as possible
    maximum_depth = find_maximum_depth(tree)
    theoretical_maximum_depth = max(0,math.ceil(math.log(len(input)+1,2)-1))
    print(("The actual maximum depth is {} while the theoretical maximum is"
          " {}").format(maximum_depth, theoretical_maximum_depth))
    assert maximum_depth == theoretical_maximum_depth

def make_random_inputs(num_lists=1, range_length=(0,33)):
    output = []
    for i in range(num_lists):
        random_length = random.randint(range_length[0], range_length[1])
        random_list = random.sample(range(-50,50), random_length)
        output.append(sorted(random_list))
    return output
        
@pytest.mark.parametrize("input", make_random_inputs(num_lists=1000))
def test_random_inputs(input):
    tree = sorted_list_to_binary_tree(input)
    recreated_input = []
    tree_to_in_order_list(tree, recreated_input)
    assert input == recreated_input
    # Make sure the tree was as compact as possible
    maximum_depth = find_maximum_depth(tree)
    theoretical_maximum_depth = max(0,math.ceil(math.log(len(input)+1,2)-1))
    assert maximum_depth == theoretical_maximum_depth


