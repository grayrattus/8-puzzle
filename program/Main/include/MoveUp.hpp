#ifndef MoveUp_HPP
#define MoveUp_HPP

#include <string>
#include "AbstractMove.hpp"

using namespace std;

class MoveUp : public AbstractMove {
public:
    State move();
    MoveUp(const State* state) ;
    virtual ~MoveUp();
};

#endif
