#include "MoveLeft.hpp"
#include "StateCantMoveException.hpp"

MoveLeft::MoveLeft(const State* state): AbstractMove{state} {

}
MoveLeft::~MoveLeft() {

}

State MoveLeft::move() {
    if ((state->getCurrentMoveElementIndex() - 1 + 1) % 3 != 0) {
        return swapPositions(state->getCurrentMoveElementIndex() - 1, state->getCurrentMoveElementIndex());
    } else {
        throw StateCantMoveException();
    }
}