#include "Solution.hpp"

Solution::Solution(): beginTime{thread_clock::now()},
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
void Solution::incrementProcessed() {
    numberOfProcessedStates++;
};
std::string Solution::toString() {
    std::string solution;
    return solution;
};