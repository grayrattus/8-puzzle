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
}

BOOST_AUTO_TEST_CASE(WriteSolutionToFileTest) {
    char *argv[] = {"main", "bfs", "RDUL", 
    "/home/grayrattus/Workspace/Uczelnia/SztucznaInteligencja/program/test/puzzles/3x3_01_00001.txt",
    "/home/grayrattus/Workspace/Uczelnia/SztucznaInteligencja/program/test/solutions/3x3_01_00001_bfs_rdul_sol.txt",
    "/home/grayrattus/Workspace/Uczelnia/SztucznaInteligencja/program/test/solutions/3x3_01_00001_bfs_rdul_stats.txt"
    };
    Solution solution;
    solution.incrementProcessed();
    solution.incrementRecurstionIndex();
    solution.incrementVisited();
    solution.addMove("L");
    solution.addMove("R");
    solution.addMove("R");
    solution.addMove("U");

    Arguments arguments{6, argv};
    AbstractAlgorithmPointer algorithm = arguments.getAlgorithm();
    algorithm->performSearch();
    arguments.writeSolutionToFiles(solution);

    std::ifstream solutionFile("/home/grayrattus/Workspace/Uczelnia/SztucznaInteligencja/program/test/solutions/3x3_01_00001_bfs_rdul_sol.txt");
    std::ifstream statsFile("/home/grayrattus/Workspace/Uczelnia/SztucznaInteligencja/program/test/solutions/3x3_01_00001_bfs_rdul_stats.txt");

    std::stringstream solutionBuffer;
    solutionBuffer << solutionFile.rdbuf();
    std::string solutionMoves = "LRRU";
    BOOST_CHECK_EQUAL(solutionMoves, solutionBuffer.str());

    std::stringstream statsBuffer;
    statsBuffer << statsFile.rdbuf();
    std:string stats = "4\n1\n1\n1\n1\n";
    BOOST_CHECK_EQUAL(stats,  statsBuffer.str());
}