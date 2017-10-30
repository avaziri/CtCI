// Copyright 2017 Andrew Vaziri
// CtCI Question # 3.3
// |||Prompt|||
// Imagine a (literal) stack of plates. If the stack gets too high, it might
// topple. Therefore in real life we would likely start a new stack when the
// previous one exceeds some threshold. Implement a data structure SetOfStacks
// that mimics this. SetOfStacks should be composed of several stacks and
// should create a new one if the previous one exceeds capacity.
// SetOfStacks.push and SetOfStacks.pop should behave identically to a single
// stack.
// |||Questions I might ask|||
// -Q: Do I need to implement any function other than push and pop? A: No
// -Q: Should I make it templated? A: yes
// -Q: Should I address corner cases like if you try to pop an empty
// SetOfStacks? A: yes
// |||Possible Implementations|||
// This is not really something that has very multiple reasonable solutions
// with different time/space complexities.

#include "../include/3.3.h"

namespace CtCI {

// |||Implementation 1|||
// Make a class with a push and pop function. It should have some private
// members: a vector of stacks, and a threshold integer.
// |||Time Complexity|||
// pushing and popping are still O(1). The worst case is that the threshold
// value is 1, and a new stack needs to be made for each element. This would
// just multiply the number of operations needed at each step by a constant, 
// therefore the original time complexity is unchanged.
// |||Space Complexity|||
// O(N) to hold all the stacks. There is some constant overhead for each
// substack, which does not change the space complexity.

template <class T>
SetOfStacks<T>::SetOfStacks(int threshold) {
    threshold_ = threshold;
    std::stack<T> initial_stack;
    substacks_.push_back(initial_stack);
}

template <class T>
void SetOfStacks<T>::push(T element) {
    // By convention the last stack will be the active one
    std::stack<T>* active_substack = &(substacks_.back());
    // Check size of active substack, if equal to threshold make new substack
    if (active_substack->size() == threshold_) {
        std::stack<T> new_active_stack;
        substacks_.push_back(new_active_stack);
        active_substack = &(substacks_.back());
    }
    // push element into active substack
    active_substack->push(element);
    return;
}

template <class T>
T SetOfStacks<T>::pop() {
    // By convention the last stack will be the active one
    std::stack<T>& active_substack = substacks_.back();
    // Pop element
    if (active_substack.empty()) {
        // This is an error!
        std::cout << "The substack is empty, this should not be possible!"
            << std::endl;
    }
    T output = active_substack.top();
    active_substack.pop();
    // Check if substack is empty, if so remove it, except if it is the last
    // substack
    if (active_substack.empty() && substacks_.size() !=1) {
        substacks_.erase(substacks_.end()-1);
    }
    return output;
}

}  // namespace CtCI
