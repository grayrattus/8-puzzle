#include "MoveUp.hpp"
#include "StateCantMoveException.hpp"

MoveUp::MoveUp(const State* state): AbstractMove{state, "U"} {

}
MoveUp::~MoveUp() {

}

State MoveUp::move() {
    if (state->getCurrentMoveElementIndex() + 1 - state->getMaxColumnsIndex() > 0) {
        return swapPositions(state->getCurrentMoveElementIndex() - 3, state->getCurrentMoveElementIndex());
    } else {
        throw StateCantMoveException();
    }
}