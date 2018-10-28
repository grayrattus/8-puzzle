#include "MoveRight.hpp"
#include "StateCantMoveException.hpp"

MoveRight::MoveRight(const State* state): AbstractMove{state} {

}
MoveRight::~MoveRight() {

}

State MoveRight::move() {
    if ((state->getCurrentMoveElementIndex() + 1) % 3 != 0) {
        return swapPositions(state->getCurrentMoveElementIndex() + 1, state->getCurrentMoveElementIndex());
    } else {
        throw StateCantMoveException();
    }
}