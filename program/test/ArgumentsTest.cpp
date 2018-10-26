#include <boost/test/unit_test.hpp>

#include "State.hpp"
#include "StateCantMoveException.hpp"
#include "BfsSearch.hpp"
#include <vector>
#include <utility>
#include <iostream>
#include "Arguments.hpp"


BOOST_AUTO_TEST_CASE(ArgumentsTest) {
    char *argv[] = {"main", "bfs", "RDUL", 
    "/home/grayrattus/Workspace/Uczelnia/SztucznaInteligencja/program/test/puzzles/3x3_01_00001.txt",
    "/home/grayrattus/Workspace/Uczelnia/SztucznaInteligencja/program/test/solutions/3x3_01_00001_bfs_rdul_sol.txt",
    "/home/grayrattus/Workspace/Uczelnia/SztucznaInteligencja/program/test/solutions/3x3_01_00001_bfs_rdul_stats.txt"
    };
    Arguments a{6, argv};
    AbstractAlgorithmPointer algorithm = a.getAlgorithm();
    std::cout << algorithm->performSearch().toString();
}