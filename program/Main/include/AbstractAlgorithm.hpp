#ifndef AbstractAlgorithm_HPP
#define AbstractAlgorithm_HPP

#include <State.hpp>
#include <Solution.hpp>
#include <memory>

using namespace std;



class AbstractAlgorithm {
public:
    State initialState;
    State goal;
    Solution solution;
    AbstractAlgorithm(State initialState, State goal);
    virtual Solution performSearch() = 0;

    virtual ~AbstractAlgorithm();

};

typedef std::unique_ptr<AbstractAlgorithm> AbstractAlgorithmPointer;

#endif
