#ifndef Solution_HPP
#define Solution_HPP

#include <boost/chrono/thread_clock.hpp>
#include <boost/chrono.hpp>
#include <string>

using namespace std;
using namespace boost::chrono;

class Solution {
private:
    int numberOfVisitedStates;
    int numberOfProcessedStates;
    thread_clock::time_point beginTime;
public:
    Solution();
    virtual ~Solution();
    std::string getExecutionTime(); 
    void incrementVisited();
    void incrementProcessed();
    std::string toString();
};

#endif
