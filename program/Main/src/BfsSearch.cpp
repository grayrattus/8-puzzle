#include "BfsSearch.hpp"
#include "StateCantMoveException.hpp"
#include <algorithm>
#include <iostream>


BfsSearch::BfsSearch(State initialState, State goal): AbstractAlgorithm{initialState, goal} {
    this->frontier.push_back(initialState);
}
BfsSearch::~BfsSearch() {

}

Solution BfsSearch::performSearch() {
    while(!frontier.empty()) {
        solution.incrementVisited();
        State state = frontier.front();
        frontier.pop_front();
        explored.insert(state);
        visited.push_back(state);

        if (state == goal) {
            std::string solutionMoves;
            auto parent = state.getParent();
            for(;;) {
                if(parent != nullptr) {
                    solutionMoves+=parent->second;
                    parent = parent->first.getParent();
                } else {
                    break;
                }
            }
            std::reverse(solutionMoves.begin(), solutionMoves.end());
            for(auto move : solutionMoves) {
                solution.addMove(std::string{move});
            }
            return solution;
        }

        for (auto neighbour : state.getNeighbours(solution)) {
            if (std::find(frontier.begin(), frontier.end(), neighbour) == frontier.end() && std::find(explored.begin(), explored.end(), neighbour) == explored.end()) {
                frontier.push_back(neighbour);
            }
        }
    }
};


/*
zrobić strukture ktora przechowuje ukladank

Struct Info {
    * parent
    string operator
    depth - głębokośc rekursji
}

Map<Uklady_ukladanki, Info>
Kiedy dodaje do frontier to uzupelniam ta mape.
*/