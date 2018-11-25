cmake_minimum_required(VERSION 3.4)
project(Main)

message("Boost_LIBRARIES: ${Boost_INCLUDE_DIRS}")

set(SOURCE_FILES 
        "src/Basic.cpp" 
        "src/State.cpp" 
        "src/BfsSearch.cpp" 
        "src/DfsSearch.cpp" 
        "src/Arguments.cpp" 
        "src/AStarHamming.cpp" 
        "src/AStarManhatan.cpp" 
        "src/AbstractAlgorithm.cpp" 
        "src/Info.cpp" 
        "src/Solution.cpp" 
        "main.cpp")

add_library(Main ${SOURCE_FILES})
target_include_directories(Main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(Main PROPERTIES LINKER_LANGUAGE CXX)

find_package (Boost 1.58.0 COMPONENTS "unit_test_framework" system chrono thread REQUIRED)
set(SOURCE_TESTER_FILES 
        ../test/master.cpp 
        ../test/StateTest.cpp
        ../test/Basic.cpp
        )
set(BFS_TESTER_FILES ../test/master.cpp ../test/BfsSearchTest.cpp)
set(DFS_TESTER_FILES ../test/master.cpp ../test/DfsSearchTest.cpp)
set(ARGUMENTS_TESTER_FILES ../test/master.cpp ../test/ArgumentsTest.cpp)
set(SOLUTION_TESTER_FILES ../test/master.cpp ../test/SolutionTest.cpp)
set(A_STAR_HAMMING_TESTER_FILES ../test/master.cpp ../test/AStarHammingTest.cpp)
set(A_STAR_MANHATAN_TESTER_FILES ../test/master.cpp ../test/AStarManhatanTest.cpp)

include_directories(Main/include ${Boost_INCLUDE_DIRS})

#add_executable("Basic" ${SOURCE_TESTER_FILES})
#target_link_libraries("Basic" "Main" ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_executable("MainProgram" ${SOURCE_FILES})
target_link_libraries("MainProgram" "Main" ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${Boost_LIBRARIES})

add_executable("StateTest" ${SOURCE_TESTER_FILES})
target_link_libraries("StateTest" "Main" ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${Boost_LIBRARIES})

add_executable("BfsSearch" ${BFS_TESTER_FILES})
target_link_libraries("BfsSearch" "Main" ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${Boost_LIBRARIES})

add_executable("DfsSearch" ${DFS_TESTER_FILES})
target_link_libraries("DfsSearch" "Main" ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${Boost_LIBRARIES})

add_executable("Arguments" ${ARGUMENTS_TESTER_FILES})
target_link_libraries("Arguments" "Main" ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} "-D_GLIBCXX_DEBUG=1" ${Boost_LIBRARIES})

add_executable("Solution" ${SOLUTION_TESTER_FILES})
target_link_libraries("Solution" "Main" ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} "-D_GLIBCXX_DEBUG=1" ${Boost_LIBRARIES})

add_executable("AStarHamming" ${A_STAR_HAMMING_TESTER_FILES})
target_link_libraries("AStarHamming" "Main" ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} "-D_GLIBCXX_DEBUG=1" ${Boost_LIBRARIES})

add_executable("AStarManhatan" ${A_STAR_MANHATAN_TESTER_FILES})
target_link_libraries("AStarManhatan" "Main" ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} "-D_GLIBCXX_DEBUG=1" ${Boost_LIBRARIES})

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose -D GLIBGLIBCXX_DEBUG
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

enable_testing()

#add_test(Basic  BasicTest)
#add_test(StateTest  StateTest)
