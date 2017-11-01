// Copyright Andrew Vaziri 2016
#include "../include/3.3.h"
#include "gtest/gtest.h"

// The fixture for testing class Foo.
class _3_3_test : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  _3_3_test() {
    // You can do set-up work for each test here.
  }

  virtual ~_3_3_test() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  // Objects declared here can be used by all tests in the test case for Foo.
};

TEST_F(_3_3_test, PushPopOneStack) {
  CtCI::SetOfStacks<int> set_of_stacks(10);
  int iterations = 5;
  for( int i = 0; i <= iterations; i++) {
      set_of_stacks.push(i);
  }
  for( int i = iterations; i !=0 ; i--) {
      EXPECT_EQ(set_of_stacks.pop(), i);
  }
}
TEST_F(_3_3_test, MultiStack) {
  CtCI::SetOfStacks<int> set_of_stacks(3);
  int iterations = 15;
  for( int i = 0; i <= iterations; i++) {
      set_of_stacks.push(i);
  }
  for( int i = iterations; i !=0 ; i--) {
      EXPECT_EQ(set_of_stacks.pop(), i);
  }
}

TEST_F(_3_3_test, PushMultipleSubStacksThenPopThem) {
  CtCI::SetOfStacks<int> set_of_stacks(3);
  std::stack<int> regular_stack;
  int iterations = 10;
  for( int i = 0; i < iterations; i++) {
      set_of_stacks.push(i);
      regular_stack.push(i);
  }
  for( int i = iterations; i > 0; i--) {
      int set_of_stacks_number = set_of_stacks.pop();
      int regular_stack_number = regular_stack.top();
      EXPECT_EQ(set_of_stacks_number, regular_stack_number);
      regular_stack.pop();
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

