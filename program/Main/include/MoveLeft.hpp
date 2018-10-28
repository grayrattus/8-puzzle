#ifndef MoveLeft_HPP
#define MoveLeft_HPP

#include <string>
#include "AbstractMove.hpp"

using namespace std;

class MoveLeft : public AbstractMove {
public:
    State move();
    MoveLeft(const State* state);
    virtual ~MoveLeft();
};

#endif
