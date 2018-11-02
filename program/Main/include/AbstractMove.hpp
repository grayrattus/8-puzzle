#ifndef AbstractMove_HPP
#define AbstractMove_HPP

#include <string>
#include <memory>
class State;


using namespace std;

class AbstractMove {
protected:
    const State* state;
    std::string moveLeter;
public:
    AbstractMove(const State* state, const std::string moveLeter);
    virtual ~AbstractMove();
    State swapPositions(const uint8_t fromIndex, const uint8_t toIndex) const;
    virtual State move() = 0;
    virtual std::string toString();
};
typedef std::shared_ptr<AbstractMove> AbstractMovePointer;

#endif
