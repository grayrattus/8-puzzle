#ifndef Arguments_HPP
#define Arguments_HPP

#include <string>
#include <vector>
#include <State.hpp>
#include <AbstractAlgorithm.hpp>
#include <fstream>

using namespace std;

class Arguments {
private: 
    int puzzleSize;
    std::vector<char> firstMoves;
    State firstStateFromFile;
    AbstractAlgorithmPointer algorithm;
    std::string inputFileName;
    std::string solutionFileName;
    std::string aditionalInformationsFileName;

    enum argumentIndex {
        ALGORITHM, FIRST_MOVES, INPUT_FILE_NAME, SOLUTION_FILE_NAME, ADITIONAL_INFORMATIONS_FILE_NAME
    };

    State parseStringToState(std::stringstream puzzle);
    std::stringstream getFileContents(std::string fileName);
public:
    Arguments(int args, char* argv[]);
    virtual ~Arguments();

};

#endif
