#ifndef ManhatanComparator_HPP
#define ManhatanComparator_HPP

#include <string>
#include <set>
#include <list>
#include <queue>
#include <vector>
#include <math.h>
#include "State.hpp"
#include "AbstractAlgorithm.hpp"
#include "ManhatanComparator.hpp"

class ManhatanComparator
{
    public:
    bool operator()(State left, State right) {
        return computeManhatanHeuristicForState(left) > computeManhatanHeuristicForState(right);
    }

    int computeManhatanHeuristicForState(State& state) {
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

        const int columnSize = 4;

        for (int i = 0; i < stateMap.size(); i++) {
            if (stateMap[i] == goalMap[i]) {
                continue;
            } else {
                heuristicValue += (abs(stateMap[i] / columnSize - i / columnSize) + abs(stateMap[i] % columnSize - i % columnSize));
            }
        }

        return heuristicValue;
    }
};

#endif
