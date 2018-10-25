#ifndef AbstractAlgorithm_HPP
#define AbstractAlgorithm_HPP

#include <State.hpp>
#include <memory>

using namespace std;


typedef std::unique_ptr<AbstractAlgorithm> AbstractAlgorithmPointer;

class AbstractAlgorithm {
public:
    State initialState;
    State goal;
    AbstractAlgorithm(State initialState, State goal);
    virtual State performSearch() = 0;

    virtual ~AbstractAlgorithm();

};

#endif
