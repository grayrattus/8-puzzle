#include "State.hpp"
#include "StateCantMoveException.hpp"
#include <algorithm>
#include "MoveRight.hpp"
#include "MoveLeft.hpp"
#include "MoveUp.hpp"
#include "MoveDown.hpp"
#include "AbstractMove.hpp"

const uint8_t State::ELEMENT_TO_SEARCH = 0;

State::State(const std::vector<uint8_t> map, const uint8_t puzzleSize) : 
    map{map}, 
    maxColumnsIndex{puzzleSize},
    maxPuzzleIndex(maxColumnsIndex*maxColumnsIndex - 1),
    moves{
        AbstractMovePointer{new MoveUp(this)},
        AbstractMovePointer{new MoveDown(this)},
        AbstractMovePointer{new MoveLeft(this)},
        AbstractMovePointer{new MoveRight(this)}
        }
{
    this->currentMoveElementIndex = std::find(map.begin(), map.end(), ELEMENT_TO_SEARCH) - map.begin();
}
State::~State() {

}
std::string State::toString() const {
    std::string toReturn = "";
    for (int index = 0; index < map.size(); index++) {
        if (index % maxColumnsIndex == 0 && index > 0) {
            toReturn.append("\n");
        } 
        toReturn.append(std::to_string(map.at(index)));
    }
    return toReturn;
};

State State::swapPositions(const uint8_t fromIndex, const uint8_t toIndex) const {
        std::vector<uint8_t> newMap = map;
        std::swap(newMap[fromIndex], newMap[toIndex]);
        return State(newMap, maxColumnsIndex);
}

std::vector<uint8_t> State::getMap() const {
    return map;
};
uint8_t State::getCurrentMoveElementIndex() const {
    return currentMoveElementIndex;
};
uint8_t State::getMaxPuzzleIndex() const {
    return maxPuzzleIndex;
};

std::vector<State> State::getNeighbours() const {
    std::vector<State> neighbours;
    for (auto singleMove : moves) {
        try {
            neighbours.push_back(singleMove->move());
        } catch (StateCantMoveException e) {
        } catch (const std::bad_alloc& e) {
        }

    }
    return neighbours;
};

uint8_t State::getMaxColumnsIndex() const { 
    return maxColumnsIndex;
};

bool operator== (const State &s1, const State &s2) {
    return s1.getMap() == s2.getMap();
}
bool operator== (const State &s1, const std::vector<uint8_t> &map) {
    return s1.getMap() == map;
}
bool State::operator<(const State &s1) const {
    return std::lexicographical_compare(this->map.begin(), this->map.end(), s1.map.begin(), s1.map.end());
};

