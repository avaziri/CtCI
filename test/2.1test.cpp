// Copyright Andrew Vaziri 2016
#include <iostream>
#include <list>

#include "../include/2.1.h"
#include "gtest/gtest.h"

// The fixture for testing class Foo.
class _2_1_test : public ::testing::Test {
 protected:
  std::list<int> input;
  // You can remove any or all of the following functions if its body
  // is empty.

  _2_1_test() {
    // You can do set-up work for each test here.
  }

  virtual ~_2_1_test() {
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

TEST_F(_2_1_test, 1handlesNoDuplicates) {
  input.push_front(1);
  input.push_front(2);
  input.push_front(3);
  input = CtCI::RemoveDups1(input);
  EXPECT_EQ(CtCI::ListToString(input), "[1, 2, 3]");
}

TEST_F(_2_1_test, 1handlesDuplicates) {
  input.push_front(1);
  input.push_front(2);
  input.push_front(3);
  input.push_front(2);
  input = CtCI::RemoveDups1(input);
  EXPECT_EQ(CtCI::ListToString(input), "[1, 3, 2]");
}

TEST_F(_2_1_test, 1handlesRepeatedDuplicates) {
  input.push_front(2);
  input.push_front(2);
  input.push_front(2);
  input.push_front(2);
  input = CtCI::RemoveDups1(input);
  EXPECT_EQ(CtCI::ListToString(input), "[2]");
}


TEST_F(_2_1_test, 1handlesEmptyList) {
  input = CtCI::RemoveDups1(input);
  EXPECT_EQ(CtCI::ListToString(input), "[]");
}

TEST_F(_2_1_test, 2handlesNoDuplicates) {
  input.push_front(1);
  input.push_front(2);
  input.push_front(3);
  input = CtCI::RemoveDups2(input);
  EXPECT_EQ(CtCI::ListToString(input), "[3, 2, 1]");
}

TEST_F(_2_1_test, 2handlesDuplicates) {
  input.push_front(1);
  input.push_front(2);
  input.push_front(3);
  input.push_front(2);
  input = CtCI::RemoveDups2(input);
  EXPECT_EQ(CtCI::ListToString(input), "[2, 3, 1]");
}

TEST_F(_2_1_test, 2handlesRepeatedDuplicates) {
  input.push_front(2);
  input.push_front(2);
  input.push_front(2);
  input.push_front(2);
  input = CtCI::RemoveDups2(input);
  EXPECT_EQ(CtCI::ListToString(input), "[2]");
}

TEST_F(_2_1_test, 2handlesEmptyList) {
  input = CtCI::RemoveDups3(input);
  EXPECT_EQ(CtCI::ListToString(input), "[]");
}

TEST_F(_2_1_test, 3handlesNoDuplicates) {
  input.push_front(1);
  input.push_front(2);
  input.push_front(3);
  input = CtCI::RemoveDups3(input);
  EXPECT_EQ(CtCI::ListToString(input), "[3, 2, 1]");
}

TEST_F(_2_1_test, 3handlesDuplicates) {
  input.push_front(1);
  input.push_front(2);
  input.push_front(3);
  input.push_front(2);
  input = CtCI::RemoveDups3(input);
  EXPECT_EQ(CtCI::ListToString(input), "[2, 3, 1]");
}

TEST_F(_2_1_test, 3handlesRepeatedDuplicates) {
  input.push_front(2);
  input.push_front(2);
  input.push_front(2);
  input.push_front(2);
  input = CtCI::RemoveDups3(input);
  EXPECT_EQ(CtCI::ListToString(input), "[2]");
}

TEST_F(_2_1_test, 3handlesEmptyList) {
  input = CtCI::RemoveDups3(input);
  EXPECT_EQ(CtCI::ListToString(input), "[]");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

