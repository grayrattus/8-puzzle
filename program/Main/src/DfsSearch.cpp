#include "DfsSearch.hpp"
#include "StateCantMoveException.hpp"
#include <algorithm>
#include <iostream>


DfsSearch::DfsSearch(State initialState, State goal): AbstractAlgorithm{initialState, goal} {
    this->frontier.push_back(initialState);
}
DfsSearch::~DfsSearch() {

}

Solution DfsSearch::performSearch() {
    int recursionLevel = 0;
    while(!frontier.empty()) {
        solution.incrementVisited();
        State state = frontier.back();
        frontier.pop_back();
        explored.insert(state);
        visited.push_back(state);
        

         auto parent = state.getParent();
         for(;;) {
             if(parent != nullptr) {
                 parent = parent->first.getParent();
                 recursionLevel++;
             } else {
                 break;
             }
         }

         if (recursionLevel > 18) {
             state = frontier.front();
             frontier.pop_front();
             recursionLevel = 0;
         }

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