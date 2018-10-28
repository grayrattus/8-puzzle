#ifndef AbstractMove_HPP
#define AbstractMove_HPP

#include <string>
#include "State.hpp"

using namespace std;

class AbstractMove {
private:
    State state;
public:
    AbstractMove(const State& state);
    virtual State move() = 0;
    virtual ~AbstractMove();
    State swapPositions(const uint8_t fromIndex, const uint8_t toIndex) const;
};

#endif
