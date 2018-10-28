#ifndef AbstractMove_HPP
#define AbstractMove_HPP

#include <string>
#include <memory>
class State;

using namespace std;

class AbstractMove {
protected:
    const State* state;
public:
    AbstractMove(const State* state);
    virtual ~AbstractMove();
    State swapPositions(const uint8_t fromIndex, const uint8_t toIndex) const;
    virtual State move() = 0;
};
typedef std::unique_ptr<AbstractMove> AbstractMovePointer;

#endif
