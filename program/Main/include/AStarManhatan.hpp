#ifndef AStarManhatan_HPP
#define AStarManhatan_HPP

#include <string>
#include <set>
#include <list>
#include <queue>
#include <vector>
#include "State.hpp"
#include "AbstractAlgorithm.hpp"
#include "ManhatanComparator.hpp"

class AStarManhatan : public AbstractAlgorithm{
private:
    std::priority_queue<int,std::vector<State>, ManhatanComparator> frontier;
    std::set<State> explored;
    std::vector<State> visited;
public:
    AStarManhatan(State initialState, State goal);
    Solution performSearch();
    virtual ~AStarManhatan();
};


#endif
