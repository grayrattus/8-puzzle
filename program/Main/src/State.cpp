#include "State.hpp"
#include "StateCantMoveException.hpp"
#include <algorithm>

const uint8_t State::ELEMENT_TO_SEARCH = 0;
const uint8_t State::MAX_COLUMNS_INDEX = 3;
const uint8_t State::MAX_PUZZLE_INDEX = 8;

State::State(const std::vector<uint8_t> map) : map{map}
{
    this->currentMoveElementIndex = std::find(map.begin(), map.end(), ELEMENT_TO_SEARCH) - map.begin();
}
State::~State() {

}
State State::moveUp() const{
    if (currentMoveElementIndex + 1 - MAX_COLUMNS_INDEX > 0) {
        return swapPositions(currentMoveElementIndex - 3, currentMoveElementIndex);
    } else {
        throw StateCantMoveException();
    }
}
State State::moveDown() const{
    if (currentMoveElementIndex + 1 + MAX_COLUMNS_INDEX <= MAX_PUZZLE_INDEX + 1) {
        return swapPositions(currentMoveElementIndex + 3, currentMoveElementIndex);
    } else {
        throw StateCantMoveException();
    }
}
State State::moveLeft() const {
    if ((currentMoveElementIndex - 1 + 1) % 3 != 0) {
        return swapPositions(currentMoveElementIndex - 1, currentMoveElementIndex);
    } else {
        throw StateCantMoveException();
    }
};
State State::moveRight() const {
    if ((currentMoveElementIndex + 1) % 3 != 0) {
        return swapPositions(currentMoveElementIndex + 1, currentMoveElementIndex);
    } else {
        throw StateCantMoveException();
    }
};
std::string State::toString() const {
    std::string toReturn = "";
    for (int index = 0; index < map.size(); index++) {
        if (index % MAX_COLUMNS_INDEX == 0 && index > 0) {
            toReturn.append("\n");
        } 
        toReturn.append(std::to_string(map.at(index)));
    }
    return toReturn;
};

State State::swapPositions(const uint8_t fromIndex, const uint8_t toIndex) const {
        std::vector<uint8_t> newMap = map;
        std::swap(newMap[fromIndex], newMap[toIndex]);
        return State(newMap);
}

std::vector<uint8_t> State::getMap() const {
    return map;
};
uint8_t State::getCurrentMoveElementIndex() const {
    return currentMoveElementIndex;
};

bool operator== (const State &s1, const State &s2) {
    return s1.getMap() == s2.getMap();
}
bool operator== (const State &s1, const std::vector<uint8_t> &map) {
    return s1.getMap() == map;
}