#include "MoveDown.hpp"
#include "StateCantMoveException.hpp"

MoveDown::MoveDown(const State* state): AbstractMove{state} {

}
MoveDown::~MoveDown() {

}

State MoveDown::move() {
    if (state->getCurrentMoveElementIndex() + 1 + state->getMaxColumnsIndex() <= state->getMaxPuzzleIndex() + 1) {
        return swapPositions(state->getCurrentMoveElementIndex() + 3, state->getCurrentMoveElementIndex());
    } else {
        throw StateCantMoveException();
    }
}