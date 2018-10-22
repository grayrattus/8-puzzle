#include "BfsSearch.hpp"
#include "StateCantMoveException.hpp"
#include <algorithm>
#include <iostream>

BfsSearch::BfsSearch(State initialState, State goal): goalTest{goal} {
    this->frontier.push_back(initialState);
}
BfsSearch::~BfsSearch() {

}

State BfsSearch::performSearch() {
    while(!frontier.empty()) {
        State state = frontier.front();
        frontier.pop_front();
        explored.push_back(state);

        if (state == goalTest) {
            return state;
        }

        for (auto neighbour : state.getNeighbours()) {
            if (std::find(frontier.begin(), frontier.end(), neighbour) == frontier.end() && std::find(explored.begin(), explored.end(), neighbour) == explored.end()) {
                frontier.push_front(neighbour);
            }
        }
    }
};