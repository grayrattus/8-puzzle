#include "State.hpp"
#include "StateCantMoveException.hpp"
#include <algorithm>

const uint8_t State::ELEMENT_TO_SEARCH = 0;

State::State(const std::vector<uint8_t> map, const uint8_t puzzleSize, std::string firstMoves) : 
    map{map}, 
    maxColumnsIndex{puzzleSize},
    maxPuzzleIndex(maxColumnsIndex*maxColumnsIndex - 1),
    firstMoves{firstMoves}
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
        return State(newMap, maxColumnsIndex, firstMoves);
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
    try {
        neighbours.push_back(this->moveDown());
    } catch (StateCantMoveException e) {
    }
    try {
        neighbours.push_back(this->moveUp());
    } catch (StateCantMoveException e) {
    }
    try {
        neighbours.push_back(this->moveLeft());
    } catch (StateCantMoveException e) {
    }
    try {
        neighbours.push_back(this->moveRight());
    } catch (StateCantMoveException e) {
    }
    return neighbours;
};

State State::moveUp() const{
    if (currentMoveElementIndex + 1 - maxColumnsIndex > 0) {
        return swapPositions(currentMoveElementIndex - 3, currentMoveElementIndex);
    } else {
        throw StateCantMoveException();
    }
}
State State::moveDown() const{
    if (currentMoveElementIndex + 1 + maxColumnsIndex <= maxPuzzleIndex + 1) {
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

