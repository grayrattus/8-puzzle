#include <Arguments.hpp>
#include <boost/program_options.hpp>

#include <BfsSearch.hpp>
#include <ostream>

Arguments::Arguments(int args, char* argv[]): 
    firstMoves{argv[argumentIndex::FIRST_MOVES]},
    firstStateFromFile{parseStringToState(getFileContents(argv[argumentIndex::INPUT_FILE_NAME]))}{

    std::string paramAlgorithmName = argv[argumentIndex::ALGORITHM];
    inputFileName = argv[argumentIndex::INPUT_FILE_NAME];
    solutionFileName = argv[argumentIndex::SOLUTION_FILE_NAME];
    aditionalInformationsFileName = argv[argumentIndex::ADITIONAL_INFORMATIONS_FILE_NAME];

    // Add save solution to file - this should be from State.toString()
    // Add save solution to aditionalInformations to file
    // Add moves 

    if (paramAlgorithmName == "bfs") {
        algorithm = AbstractAlgorithmPointer{new BfsSearch{firstStateFromFile, State{std::vector<uint8_t>{1, 2, 3, 4, 5, 6, 7, 8, 0}, puzzleSize,firstMoves }}};
    }


}
Arguments::~Arguments() {

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
    return State{stateMap, puzzleSize, firstMoves};
}

AbstractAlgorithmPointer Arguments::getAlgorithm() {
    return std::move(algorithm);
};