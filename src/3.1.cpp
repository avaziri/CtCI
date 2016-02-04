// Copyright 2016 Andrew Vaziri
// CtCI Question #3.1
// |||Prompt|||
// Describe how you could use single array to implement three stacks.
// |||Questions I might ask|||
// --Am I more worried about time complexity or space complexity?
// --Can I use some of the array as pointers to other parts of the array?
// --Can I have variables in memory outside the array? Perhaps a couple of
// pointers?

// |||Possible Implementations|||


#include "../include/#######"

namespace CtCI {

// |||Implementation 1|||
// Split the array into 3 equal parts. These parts have a fixed size, so 
// one stack might run out of space before the others. This has the 
// disadvantage of not fully utilizing the space, but should be simple to
// code and fast. This requires 6 pointers outside the array. 3 for the heads
// 3 for tails.. Once a stack runs out of room an exception is thrown.
// |||Time Complexity|||
// N=number of elements in all stacks. Pop, push, peek, and isEmpty are O(1)
// |||Space Complexity|||
// O(N) 

// |||Implementation 2||
// Use 6 pointers to keep track of the heads and tails of each list. Initialize
// them equally spaced  apart to begin. When a stack tries to push on a new value
// but there is no room, recursively check if the abutting stack(s) have room
// on their far side. If so shift, all the elements over to make room. This
// will be inefficent, but will eventually use all the avaliale room. Once
// all space has been used an exception is thrown.
// |||Time Complexity|||
// N= the number of elements in all stacks. In the case that a shift is needed
// the algorithm can detect where the space is in O(1) by using the head and
// tail pointers. It must then move all the elements to make room. This means
// push is O(N), pop and peek are O(1), isEmpty is O(1) 
// |||Space Complexity|||
// O(N)

// |||Implementation 3|||
// Same as implemnetaion 2, but allow for a circular array to improve the time
// efficency on average, as less shifts of all elements will be needed.
// |||Time Complexity|||
// same as above
// |||Space Complexity|||
// same as above


// |||Implementation 1|||
// Dont try and bastardize the performance of the stacks to get them to fit in
// the array. Instead treat the array as a bunch of memory holding linked list
// nodes, meaning that every even address is a value, every odd address is a
// pointer. Basically we will make our own dynamic memory allocation. Initially
// all the entries form a single linked list, namely the "free memory" linked
// list. As any number of stacks are initialized a node is removed from free
// memory and given to the list. This process continues until the free memory
// linked list is empty and receives a push request, at which point an error
// is thrown.
// |||Time Complexity|||
// N=number of elements in a single stack. Pop, peek, push, isEmpty O(1)
// |||Space Complexity|||
// O(N/2) = O(N)


}  // namespace CtCI
