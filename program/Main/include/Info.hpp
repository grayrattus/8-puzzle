#ifndef Info_HPP
#define Info_HPP

class State;

#include <string>

class Info {
private:
    const State& parent;
    std::string move;
    int recursionLevel;
public:
    Info(const State& parent, std::string move, int recursionLevel);
    ~Info();
};
#endif