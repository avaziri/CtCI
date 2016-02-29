#The following is commented because it is a bad idea to automatically add
#source files using GLOB. This will cause it to fail to rebuild when
#necessary because even if source files change, no cmake files will have
#changed so no new makefiles are generated

#file( GLOB TEST_SOURCES RELATIVE ${CMAKE_BINARY_DIR}/test *cpp )
#message ( "${TEST_SOURCES}" )
#foreach( test_source_name ${TEST_SOURCES} )
#  string( REPLACE ".cpp" "" test_exe_name ${test_source_name} )
#  string( REPLACE "test.cpp" "lib" test_lib_name ${test_source_name} )
#  add_executable( ${test_exe_name} ${test_source_name} )
#  target_link_libraries( ${test_exe_name} gtest gtest_main ) 
#  target_link_libraries( ${test_exe_name} ${test_lib_name} )
#endforeach( test_source_name ${TEST_SOURCES} )


add_executable(1.1test 1.1test.cpp)
# Linking for gtest stuff
target_link_libraries(1.1test gtest gtest_main)
# Linking for the project
target_link_libraries(1.1test 1.1lib)

add_executable(1.2test 1.2test.cpp)
target_link_libraries(1.2test gtest gtest_main)
target_link_libraries(1.2test 1.2lib)

add_executable(2.1test 2.1test.cpp)
target_link_libraries(2.1test gtest gtest_main)
target_link_libraries(2.1test 2.1lib)

add_executable(2.2test 2.2test.cpp)
target_link_libraries(2.2test gtest gtest_main)
target_link_libraries(2.2test 2.2lib)

add_executable(2.4test 2.4test.cpp)
target_link_libraries(2.4test gtest gtest_main)
target_link_libraries(2.4test 2.4lib)

