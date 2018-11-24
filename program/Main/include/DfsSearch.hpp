#ifndef DfsSearch_HPP
#define DfsSearch_HPP

#include <string>
#include <set>
#include <list>
#include <vector>
#include "State.hpp"
#include "AbstractAlgorithm.hpp"

class DfsSearch : public AbstractAlgorithm{
private:
    std::list<State> frontier;
    std::set<State> explored;
    std::vector<State> visited;
public:
    DfsSearch(State initialState, State goal);
    Solution performSearch();
    virtual ~DfsSearch();
};


#endif
