cmake_minimum_required(VERSION 3.4)
project(Main)

set(SOURCE_FILES 
        "src/Basic.cpp" 
        "src/State.cpp" 
        "src/BfsSearch.cpp" 
        "main.cpp")

add_library(Main ${SOURCE_FILES})
target_include_directories(Main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(Main PROPERTIES LINKER_LANGUAGE CXX)

find_package (Boost 1.58.0 COMPONENTS "unit_test_framework" REQUIRED)
set(SOURCE_TESTER_FILES 
        ../test/master.cpp 
        ../test/StateTest.cpp
        ../test/BfsSearchTest.cpp
        ../test/Basic.cpp
        )

include_directories(Main/include ${Boost_INCLUDE_DIRS})

#add_executable("Basic" ${SOURCE_TESTER_FILES})
#target_link_libraries("Basic" "Main" ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_executable("StateTest" ${SOURCE_TESTER_FILES})
target_link_libraries("StateTest" "Main" ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_executable("BfsSearch" ${SOURCE_TESTER_FILES})
target_link_libraries("BfsSearch" "Main" ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

enable_testing()

#add_test(Basic  BasicTest)
#add_test(StateTest  StateTest)
