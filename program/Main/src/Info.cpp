#include <Info.hpp>

Info::Info(const State& parent, std::string move, int recursionLevel):
    parent{parent}, move{move}, recursionLevel{recursionLevel} {

    };
Info::~Info() {

}