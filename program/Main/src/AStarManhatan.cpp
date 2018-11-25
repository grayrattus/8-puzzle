#include "AStarManhatan.hpp"
#include "StateCantMoveException.hpp"
#include <algorithm>
#include <iostream>


AStarManhatan::AStarManhatan(State initialState, State goal): AbstractAlgorithm{initialState, goal} {
    this->frontier.push(initialState);
}
AStarManhatan::~AStarManhatan() {

}

Solution AStarManhatan::performSearch() {
    while(!frontier.empty()) {
        solution.incrementVisited();
        auto state = frontier.top();
        frontier.pop();
        explored.insert(state);

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
            if (std::find(explored.begin(), explored.end(), neighbour) == explored.end()) {
                frontier.push(neighbour);
            }
        }
    }
};