#ifndef BfsSearch_HPP
#define BfsSearch_HPP

#include <string>
#include <set>
#include <list>
#include <vector>
#include "State.hpp"
#include "AbstractAlgorithm.hpp"

class BfsSearch : public AbstractAlgorithm{
private:
    std::list<State> frontier;
    std::set<State> explored;
public:
    BfsSearch(State initialState, State goal);
    State performSearch();
    virtual ~BfsSearch();
};


#endif
