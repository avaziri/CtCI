// Copyright Andrew Vaziri 2016
#include <iostream>
#include <list>
#include <sstream>
#include <string>

#include "../include/2.1.h"
#include "gtest/gtest.h"

// Helper Function
std::string ListToString(std::list<int> L) {
  std::stringstream ss;
  ss << "[";
  for (std::list<int>::const_iterator it = L.begin(); it != L.end(); ++it) {
    if (it == L.begin()) {
      ss << *it;
    } else {
      ss << ", " << *it;
    }
  }
  ss << "]";
  return ss.str();
}

// The fixture for testing class Foo.
class _2_1_test : public ::testing::Test {
 protected:
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
  std::list<int> input{3, 2, 1};
  input = CtCI::RemoveDups1(input);
  EXPECT_EQ(ListToString(input), "[1, 2, 3]");
}

TEST_F(_2_1_test, 1handlesDuplicates) {
  std::list<int> input{2, 3, 2, 1};
  input = CtCI::RemoveDups1(input);
  EXPECT_EQ(ListToString(input), "[1, 3, 2]");
}

TEST_F(_2_1_test, 1handlesRepeatedDuplicates) {
  std::list<int> input{2, 2, 2, 2, 2, 2, 2, 2, 2};
  input = CtCI::RemoveDups1(input);
  EXPECT_EQ(ListToString(input), "[2]");
}

TEST_F(_2_1_test, 1handlesEmptyList) {
  std::list<int> input;
  input = CtCI::RemoveDups1(input);
  EXPECT_EQ(ListToString(input), "[]");
}

TEST_F(_2_1_test, 2handlesNoDuplicates) {
  std::list<int> input{3, 2, 1};
  input = CtCI::RemoveDups2(input);
  EXPECT_EQ(ListToString(input), "[3, 2, 1]");
}

TEST_F(_2_1_test, 2handlesDuplicates) {
  std::list<int> input{2, 3, 2, 1};
  input = CtCI::RemoveDups2(input);
  EXPECT_EQ(ListToString(input), "[2, 3, 1]");
}

TEST_F(_2_1_test, 2handlesRepeatedDuplicates) {
  std::list<int> input{2, 2, 2, 2, 2, 2, 2, 2, 2};
  input = CtCI::RemoveDups2(input);
  EXPECT_EQ(ListToString(input), "[2]");
}

TEST_F(_2_1_test, 2handlesEmptyList) {
  std::list<int> input;
  input = CtCI::RemoveDups3(input);
  EXPECT_EQ(ListToString(input), "[]");
}

TEST_F(_2_1_test, 3handlesNoDuplicates) {
  std::list<int> input{3, 2, 1};
  input = CtCI::RemoveDups3(input);
  EXPECT_EQ(ListToString(input), "[3, 2, 1]");
}

TEST_F(_2_1_test, 3handlesDuplicates) {
  std::list<int> input{2, 3, 2, 1};
  input = CtCI::RemoveDups3(input);
  EXPECT_EQ(ListToString(input), "[2, 3, 1]");
}

TEST_F(_2_1_test, 3handlesRepeatedDuplicates) {
  std::list<int> input{2, 2, 2, 2, 2, 2, 2, 2, 2};
  input = CtCI::RemoveDups3(input);
  EXPECT_EQ(ListToString(input), "[2]");
}

TEST_F(_2_1_test, 3handlesEmptyList) {
  std::list<int> input;
  input = CtCI::RemoveDups3(input);
  EXPECT_EQ(ListToString(input), "[]");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

