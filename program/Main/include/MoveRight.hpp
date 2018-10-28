#ifndef MoveRight_HPP
#define MoveRight_HPP

#include <string>
#include "AbstractMove.hpp"
#include "State.hpp"

using namespace std;

class MoveRight : public AbstractMove {
public:
    State move();
    MoveRight(const State* state);
    virtual ~MoveRight();
};

#endif
