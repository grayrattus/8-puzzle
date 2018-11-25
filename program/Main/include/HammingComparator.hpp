#ifndef HammingComparator_HPP
#define HammingComparator_HPP

#include <string>
#include <set>
#include <list>
#include <queue>
#include <vector>
#include "State.hpp"
#include "AbstractAlgorithm.hpp"
#include "HammingComparator.hpp"

class HammingComparator
{
    public:
    bool operator()(State left, State right) {
        return computeHammingHeuristicForState(left) > computeHammingHeuristicForState(right);
    }

    int computeHammingHeuristicForState(State& state) {
        int heuristicValue = 0;
        auto stateMap = state.getMap();
        auto goalMap = std::vector<std::uint8_t>{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};

        auto parent = state.getParent();

        for(;;) {
            if(parent != nullptr) {
                parent = parent->first.getParent();
                heuristicValue++;
            } else {
                break;
            }
        }
        
        auto foundMismatch = std::mismatch(stateMap.begin(), stateMap.end(), goalMap.begin());

        while (foundMismatch.first != stateMap.end()) {
            foundMismatch = std::mismatch(++foundMismatch.first, stateMap.end(), ++foundMismatch.second);
            heuristicValue++;
        }

        return heuristicValue;
    }
};

#endif
