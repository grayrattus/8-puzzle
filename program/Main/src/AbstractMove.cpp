#include "AbstractMove.hpp"

AbstractMove::AbstractMove(const State* state): state{state} {
}
AbstractMove::~AbstractMove() {

}
State AbstractMove::swapPositions(const uint8_t fromIndex, const uint8_t toIndex) const {
        std::vector<uint8_t> newMap = state->getMap();
        std::swap(newMap[fromIndex], newMap[toIndex]);
        return State(newMap, state->getMaxColumnsIndex());
}