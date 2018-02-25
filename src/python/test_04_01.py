# Copyright 2017 Andrew Vaziri
# CtCI Question #4.1
# |||Prompt|||
# Given a directed graph, design an algorithm to find out whether there is a
# route between two nodes.
# |||Questions I might ask|||
# Q: Should I also make up some data structure to represent the graph? A: Sure
# Q: Is a not considered to be connected to itself? A: Yes
# Q: Should I handle the case that the user inputs nodes that arent in the
# graph? A: Yes
# Q: Can I assume there may be cycles in the graph? A: Yes

import pytest

# |||Implementation 1|||
# Create a visited list, and a to_visit list. Use BFS or DFS to find a path if
# one exists.
# |||Time Complexity|||
# This should have the same Big 0 as Breadth First Search as that is the
# algorithm it is based off of. O(N+E) where N is number of nodes and
# E is number of edges. However, this code is checking if things are in the
# visted or to_visit lists quite often. Those operations may be O(N) when
# computed naively. This could be corrected by using hashing to make them O(1).
# Without the correction I think the run time of this would be more like
# O(N) for checking the adjacency list + O(E) for adding to the to_visit list
# + O(E*N) for checking if something is in the visted list before adding it to
# the to_visit list so O(E*N+E+N) overall.
def nodes_have_route(graph, start, end):
    if (start not in graph or end not in graph):
        return False
    if (start == end):
        return True
    visited = [start]
    to_visit = graph[start]
    # Continue while to_visit is not empty
    while (to_visit):
        print("Visited list: {}".format(visited))
        print("To visit list: {}".format(to_visit))
        current_node = to_visit[0]
        if (current_node == end):
            return True
        if (current_node in visited):
            to_visit.remove(current_node)
        else:
            visited.append(current_node)
            to_visit += [node for node in graph[current_node] if node not in visited]
            to_visit.remove(current_node)
    return False


def test_positive_three_node_graph():
    graph = { "A" : ["B", "C"],
              "B" : ["C"],
              "C" : ["A"]}
    assert nodes_have_route(graph, "B", "C")

def test_disconnected_three_node_graph():
    graph = { "A" : ["B", "C"],
              "B" : ["C"],
              "C" : ["B"]}
    assert not nodes_have_route(graph, "B", "A")

def test_not_in_graph():
    graph = { "A" : ["B", "C"],
              "B" : ["C"],
              "C" : ["B"]}
    assert not nodes_have_route(graph, "D", "A")

def test_self_path():
    graph = { "A" : ["B", "C"],
              "B" : ["C"],
              "C" : ["B"]}
    assert nodes_have_route(graph, "A", "A")

def test_self_path_and_not_in_graph():
    graph = { "A" : ["B", "C"],
              "B" : ["C"],
              "C" : ["B"]}
    assert not nodes_have_route(graph, "D", "D")
