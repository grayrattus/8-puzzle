#include "Solution.hpp"
#include <ostream>
#include <numeric>

Solution::Solution(): beginTime{thread_clock::now()},
    recurstionIndex{0}, 
    numberOfProcessedStates{0}, 
    numberOfVisitedStates{0} {

};
Solution::~Solution() {

};

std::string Solution::getExecutionTime() {
    return std::to_string(duration_cast<milliseconds>(thread_clock::now()-beginTime).count());
}
void Solution::incrementVisited() {
    numberOfVisitedStates++;
};
void Solution::incrementRecurstionIndex() {
    recurstionIndex++;
};
void Solution::incrementProcessed() {
    numberOfProcessedStates++;
};

void Solution::addMove(std::string move) {
    performedMoves.push_back(move);
};
std::string Solution::toString() {
    std::ostringstream solution;
    solution << performedMoves.size() << "\n" << numberOfVisitedStates << "\n" 
    << numberOfProcessedStates << "\n" << recurstionIndex << "\n" <<
    getExecutionTime() << "\n";
    return solution.str();
};

std::string Solution::getMoves() {
    return std::accumulate(performedMoves.begin(), performedMoves.end(), std::string(""));
};