#ifndef Solution_HPP
#define Solution_HPP

#include <boost/chrono/thread_clock.hpp>
#include <boost/chrono.hpp>
#include <string>
#include "Info.hpp"
#include "State.hpp"
#include <map>

using namespace boost::chrono;

class Solution {
private:
    int numberOfVisitedStates;
    int numberOfProcessedStates;
    int recurstionIndex;
    std::vector<std::string> performedMoves;
    thread_clock::time_point beginTime;
    std::map<State, Info> infos;
public:
    Solution();
    virtual ~Solution();
    std::string getExecutionTime(); 
    void incrementVisited();
    void incrementProcessed();
    void incrementRecurstionIndex();
    void addMove(std::string move);
    std::string toString();
    std::string getMoves();
};

#endif
