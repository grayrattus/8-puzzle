#ifndef MoveDown_HPP
#define MoveDown_HPP

#include <string>
#include "AbstractMove.hpp"

using namespace std;

class MoveDown : public AbstractMove {
public:
    State move();
    MoveDown(const State* state);
    virtual ~MoveDown();
};

#endif
