// Copyright 2016 Andrew Vaziri
// CtCI Question #2.3
// |||Prompt|||
// Implement an algorithm to delete a node in the middle (i.e., any node but
// the first and last node, not the exact middle) of a singly linked list, 
// given only access to that list.
// |||Questions I might ask|||
// --Since it makes not sense to try and use C++ STL containers for this
// probelm can we assume we have a simple node class with a data and next 
// memebrs? A: Sure
// --So the method will return nothing? It will just modify the list? A:Sure

// |||Possible Implementations|||

namespace CtCI {

// |||Implementation 1|||
// We cant delete the node we are given directly becuase the node before it 
// will continue to point to its location. So we will make the node we are 
// given assume the identity of the next node, then delete the next node.
// |||Time Complexity|||
// N = # of elements in the list. O(1) there is a constant amount of work
// to delete 1 element regardless of the size of the list.
// |||Space Complexity|||
// O(1), there is a constant amount of space to store the intermediate values

void DeleteNode(node* n) {
	n->data = n->next->data;
	node * temp = n->next->next;
	delte(n->next);
	n->next = temp;
}

}  // namespace CtCI