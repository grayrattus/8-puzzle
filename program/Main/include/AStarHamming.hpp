#ifndef AStarHamming_HPP
#define AStarHamming_HPP

#include <string>
#include <set>
#include <list>
#include <vector>
#include "State.hpp"
#include "AbstractAlgorithm.hpp"

class AStarHamming : public AbstractAlgorithm{
private:
    std::list<State> frontier;
    std::set<State> explored;
    std::vector<State> visited;
public:
    AStarHamming(State initialState, State goal);
    Solution performSearch();
    virtual ~AStarHamming();
};


#endif
