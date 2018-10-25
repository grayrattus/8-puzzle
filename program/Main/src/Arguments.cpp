#include <Arguments.hpp>
#include <boost/program_options.hpp>

#include <BfsSearch.hpp>
#include <ostream>
#include <stringstream>

Arguments::Arguments(int args, char* argv[]) {
    std::string paramAlgorithmName{argv[argumentIndex::ALGORITHM]};
    inputFileName = argv[argumentIndex::INPUT_FILE_NAME];
    solutionFileName = argv[argumentIndex::SOLUTION_FILE_NAME];
    aditionalInformationsFileName = argv[argumentIndex::ADITIONAL_INFORMATIONS_FILE_NAME];

    firstStateFromFile = parseStringToState(getFileContents(inputFileName));

    // Add save solution to file - this should be from State.toString()
    // Add save solution to aditionalInformations to file
    // Add moves 

    if (paramAlgorithmName == "bfs") {
        algorithm = AbstractAlgorithmPointer{new BfsSearch{}}
    }


}

std::stringstream Arguments::getFileContents(std::string fileName) {
    ifstream inputFile;
    inputFile.open(inputFileName);

    std::stringstream inputFileStream;
    inputFileStream << inputFile.rdbuf();
    return inputFileStream;
}

State Arguments::parseStringToState(std::stringstream puzzle) {
    std::string puzzleSizeTmp;
    puzzle >> puzzleSizeTmp;
    puzzle >> puzzleSizeTmp;
    puzzleSize = std::stoi(puzzleSizeTmp);

    std::vector<uint_8> stateMap;
    std::string puzzleNumber;
    while (puzzle >> puzzleNumber) {
        stateMap.push_back((unsigned)std::stoi(puzzleNumber));
    }
    return State{stateMap};
}