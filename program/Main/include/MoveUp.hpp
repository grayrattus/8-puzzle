#ifndef MoveUp_HPP
#define MoveUp_HPP

#include <string>
#include "AbstractMove.hpp"
#include "State.hpp"

using namespace std;

class MoveUp : public AbstractMove {
private:
public:
    State move();
    MoveUp(const State* state) ;
    virtual ~MoveUp();
};

#endif
