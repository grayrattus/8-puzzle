#ifndef AStarHamming_HPP
#define AStarHamming_HPP

#include <string>
#include <set>
#include <list>
#include <queue>
#include <vector>
#include "State.hpp"
#include "AbstractAlgorithm.hpp"
#include "HammingComparator.hpp"

class AStarHamming : public AbstractAlgorithm{
private:
    std::priority_queue<int,std::vector<State>, HammingComparator> frontier;
    std::set<State> explored;
    std::vector<State> visited;
public:
    AStarHamming(State initialState, State goal);
    Solution performSearch();
    virtual ~AStarHamming();
};


#endif
