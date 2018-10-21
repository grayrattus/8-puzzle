#include "BfsSearch.hpp"
#include "StateCantMoveException.hpp"
#include <algorithm>
#include <iostream>

BfsSearch::BfsSearch(State initialState, State goal): goalTest{goal} {
    this->frontier;
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

        auto neighbours = state.getNeighbours();
        for (auto neighbour : neighbours) {
            if (std::find(frontier.begin(), frontier.end(), state) == frontier.end() && std::find(explored.begin(), explored.end(), state) == explored.end()) {
                frontier.push_front(neighbour);
            }
        }
    }
};