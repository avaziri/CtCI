cmake_minimum_required(VERSION 2.8)

#Largely inspired by https://github.com/dmonopoly/gtest-cmake-example

#Options
option(test_enable "Build all tests." ON) #Boolean to enable 'test'

#Project Name
project(CtCI)

#Compile and Link Flags
SET(GCC_COVERAGE_COMPILE_FLAGS "-pthread -std=c++11 -g -Wall")

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

#Output File Locaitons
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#Subdirectories containing libraries and executables
add_subdirectory(src)

#Testing
if(test_enable)
  # Locate Gtest
  add_subdirectory(test)
  enable_testing()
endif()
