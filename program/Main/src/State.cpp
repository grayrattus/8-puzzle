#include "State.hpp"
#include "StateCantMoveException.hpp"
#include <algorithm>

const uint8_t State::ELEMENT_TO_SEARCH = 0;

State::State(
    const std::vector<uint8_t> map,
    const uint8_t puzzleSize,
    std::string firstMoves,
    const std::string movedFrom,
    std::pair<State, std::string>* parent) : map{map},
                                                   maxColumnsIndex{puzzleSize},
                                                   maxPuzzleIndex(maxColumnsIndex * maxColumnsIndex - 1),
                                                   firstMoves{firstMoves},
                                                   movedFrom(movedFrom),
                                                   parent{parent}
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

State State::swapPositions(const uint8_t fromIndex, const uint8_t toIndex, const std::string movedFrom) const {
        std::vector<uint8_t> newMap = map;
        std::swap(newMap[fromIndex], newMap[toIndex]);
        std::pair<State, std::string>* parentPtr = new std::pair<State, std::string>(*this, movedFrom);
        return State(newMap, maxColumnsIndex, firstMoves, movedFrom, parentPtr);
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

std::vector<State> State::getNeighbours(Solution& solution) const {
    std::vector<State> neighbours;
    for (auto moveLeter : firstMoves) {
        try {
            switch (moveLeter) {
                case ('U'):
                    neighbours.push_back(this->moveUp());
                    break;
                case ('D'):
                    neighbours.push_back(this->moveDown());
                    break;
                case ('L'):
                    neighbours.push_back(this->moveLeft());
                    break;
                case ('R'):
                    neighbours.push_back(this->moveRight());
                    break;
            }
        }
        catch (StateCantMoveException e) {
        }
    }
    return neighbours;
};

State State::moveUp() const{
    if (currentMoveElementIndex + 1 - maxColumnsIndex > 0) {
        return swapPositions(currentMoveElementIndex - maxColumnsIndex, currentMoveElementIndex, "U");
    } else {
        throw StateCantMoveException();
    }
}
State State::moveDown() const{
    if (currentMoveElementIndex + 1 + maxColumnsIndex <= maxPuzzleIndex + 1) {
        return swapPositions(currentMoveElementIndex + maxColumnsIndex, currentMoveElementIndex, "D");
    } else {
        throw StateCantMoveException();
    }
}
State State::moveLeft() const {
    if ((currentMoveElementIndex - 1 + 1) % maxColumnsIndex != 0) {
        return swapPositions(currentMoveElementIndex - 1, currentMoveElementIndex, "L");
    } else {
        throw StateCantMoveException();
    }
};
State State::moveRight() const {
    if ((currentMoveElementIndex + 1) % maxColumnsIndex != 0) {
        return swapPositions(currentMoveElementIndex + 1, currentMoveElementIndex, "R");
    } else {
        throw StateCantMoveException();
    }
};

uint8_t State::getMaxColumnsIndex() const { 
    return maxColumnsIndex;
};
std::string State::getMovedFrom() const {
    return movedFrom;
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
std::pair<State, std::string> *State::getParent()
{
    return parent;
};