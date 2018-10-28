#ifndef State_HPP
#define State_HPP

#include <string>
#include <vector>
#include <string>

using namespace std;

class State {
private:
    std::vector<uint8_t> map;
    static const uint8_t ELEMENT_TO_SEARCH;
    uint8_t maxColumnsIndex;
    uint8_t maxPuzzleIndex;
    uint8_t currentMoveElementIndex;
    State swapPositions(const uint8_t fromIndex, const uint8_t toIndex) const;
public:
    State(const std::vector<uint8_t> map, const uint8_t puzzleSize);
    virtual ~State();
    State moveUp() const;
    State moveDown() const;
    State moveLeft() const;
    State moveRight() const;
    std::vector<State> getNeighbours() const;
    std::string toString() const;
    std::vector<uint8_t> getMap() const;
    uint8_t getCurrentMoveElementIndex() const;
    uint8_t getMaxColumnsIndex() const;
    friend bool operator== (const State &s1, const State &s2);
    friend bool operator== (const State &s1, const std::vector<uint8_t> &map);
    bool operator< (const State &s1) const;
};


#endif
