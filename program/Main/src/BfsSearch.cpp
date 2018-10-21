#include "BfsSearch.hpp"
#include "StateCantMoveException.hpp"
#include <algorithm>

BfsSearch::BfsSearch(const State& initialState, const State& goal): goalTest{goal} {
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
            if (std::any_of(frontier.begin(), frontier.end(), [=](State searchState) {
                return searchState == state;
            }) && std::any_of(explored.begin(), explored.end(), [=](State searchState) {
                return searchState == state;
            })) {
                frontier.push_front(neighbour);
            }
        }
    }
};