#include <Arguments.hpp>
#include <boost/program_options.hpp>

#include <BfsSearch.hpp>
#include <DfsSearch.hpp>
#include <AStarHamming.hpp>
#include <ostream>
#include <iostream>

Arguments::Arguments(int args, char* argv[]): 
    firstMoves{checkFirstMoves(argv[argumentIndex::FIRST_MOVES])},
    firstStateFromFile{parseStringToState(getFileContents(argv[argumentIndex::INPUT_FILE_NAME]))}{

    std::string paramAlgorithmName = argv[argumentIndex::ALGORITHM];
    inputFileName = argv[argumentIndex::INPUT_FILE_NAME];
    solutionFileName = argv[argumentIndex::SOLUTION_FILE_NAME];
    aditionalInformationsFileName = argv[argumentIndex::ADITIONAL_INFORMATIONS_FILE_NAME];

    if (paramAlgorithmName == "bfs") {
        algorithm = AbstractAlgorithmPointer{
            new BfsSearch{
                firstStateFromFile, 
                State{
                    std::vector<uint8_t>{1, 2, 3, 4,
                                         5, 6, 7, 8, 
                                         9, 10, 11, 12,
                                         13, 14, 15, 0}, 
                    puzzleSize,
                    firstMoves}
                }
        };
    } else if (paramAlgorithmName == "dfs") {
        algorithm = AbstractAlgorithmPointer{
            new DfsSearch{
                firstStateFromFile, 
                State{
                    std::vector<uint8_t>{1, 2, 3, 4,
                                         5, 6, 7, 8, 
                                         9, 10, 11, 12,
                                         13, 14, 15, 0}, 
                    puzzleSize,
                    firstMoves}
                }
        };
    } else if (paramAlgorithmName == "astr") {
         firstMoves = "RDUL";
         algorithm = AbstractAlgorithmPointer{
             new AStarHamming{
                 firstStateFromFile, 
                 State{
                     std::vector<uint8_t>{1, 2, 3, 4,
                                          5, 6, 7, 8, 
                                          9, 10, 11, 12,
                                          13, 14, 15, 0}, 
                     puzzleSize,
                     firstMoves}
                 }
         };
    }


}
Arguments::~Arguments() {

}

std::string Arguments::checkFirstMoves(char* firstMoves) {
    if (firstMoves == "hamm") {
        return "RDUL";
    }
    return firstMoves;
}


std::stringstream Arguments::getFileContents(char* fileName) {
    std::string name(fileName);
    ifstream inputFile;
    inputFile.open(name);

    std::stringstream inputFileStream;
    inputFileStream << inputFile.rdbuf();
    std::string test = inputFileStream.str();
    return inputFileStream;
}

State Arguments::parseStringToState(std::stringstream puzzle) {
    std::string puzzleSizeTmp;
    puzzle >> puzzleSizeTmp;
    puzzle >> puzzleSizeTmp;
    puzzleSize = (unsigned)std::stoi(puzzleSizeTmp);

    std::vector<uint8_t> stateMap;
    std::string puzzleNumber;
    while (puzzle >> puzzleNumber) {
        stateMap.push_back((unsigned)std::stoi(puzzleNumber));
    }
    if (firstMoves == "hamm") {
        firstMoves = "RDUL";
    }
    return State{stateMap, puzzleSize, firstMoves};
}

AbstractAlgorithmPointer Arguments::getAlgorithm() {
    return std::move(algorithm);
};

void Arguments::writeSolutionToFiles(Solution& solution) {
    ofstream solutionFile(solutionFileName);
    ofstream aditionalInformationFile(aditionalInformationsFileName);

    solutionFile << solution.getMoves();
    aditionalInformationFile << solution.toString();
    solutionFile.close();
    aditionalInformationFile.close();
};