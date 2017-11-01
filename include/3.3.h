// Copyright 2017 Andrew Vaziri
#ifndef _3_3_H
#define _3_3_H
#include <stack>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

namespace CtCI {

template <class T>
class SetOfStacks {
 public:
    // Constructor.
    explicit SetOfStacks(int threshold);
    // Function to push an element onto the top of the active substack.
    void push(T element);
    // Function to pop an element off the top of the active substack.
    T pop();
 private:
    // Set of substacks
    std::vector<std::stack<T>> substacks_;
    // Threshold which defines the maximum size of each substack
    std::size_t threshold_;
};

// Explicitly force the int specialization to be compiled
template class SetOfStacks<int>;

}  // namespace CtCI
#endif  // _3_3_H
