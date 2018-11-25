#ifndef Arguments_HPP
#define Arguments_HPP

#include <string>
#include <vector>
#include <State.hpp>
#include <AbstractAlgorithm.hpp>
#include <fstream>
#include <sstream>
#include "Solution.hpp"

using namespace std;

class Arguments {
private: 
    uint8_t puzzleSize;
    std::string firstMoves;
    State firstStateFromFile;
    AbstractAlgorithmPointer algorithm;
    std::string inputFileName;
    std::string solutionFileName;
    std::string aditionalInformationsFileName;

    enum argumentIndex {
        PROGRAM_NAME, ALGORITHM, FIRST_MOVES, INPUT_FILE_NAME, SOLUTION_FILE_NAME, ADITIONAL_INFORMATIONS_FILE_NAME
    };

    State parseStringToState(std::stringstream puzzle);
    std::stringstream getFileContents(char* fileName);
    std::string checkFirstMoves(char* firstMoves); 
public:
    Arguments(int args, char* argv[]);
    void writeSolutionToFiles(Solution& solution);
    AbstractAlgorithmPointer getAlgorithm();
    virtual ~Arguments();

};

#endif
