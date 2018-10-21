#ifndef BfsSearch_HPP
#define BfsSearch_HPP

#include <string>
#include <set>
#include <list>
#include <vector>
#include "State.hpp"

class BfsSearch {
private:
    std::list<State> frontier;
    std::vector<State> explored;
    State goalTest;
public:
    BfsSearch(State initialState, State goal);
    State performSearch();
    virtual ~BfsSearch();
};


#endif
