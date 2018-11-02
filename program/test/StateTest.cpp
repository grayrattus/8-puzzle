#include <boost/test/unit_test.hpp>

#include "State.hpp"
#include "StateCantMoveException.hpp"
#include <vector>
#include <utility>
#include <iostream>

const uint8_t PUZZLE_SIZE = 3;

BOOST_AUTO_TEST_CASE(StateConstructorTest) {
    std::vector<uint8_t> map{1,2,5,3,4,0,6,7,8};
    State s(map, PUZZLE_SIZE);
    State s1(map, PUZZLE_SIZE);

    BOOST_CHECK(s == s1);
    BOOST_CHECK(s == map);
}

BOOST_AUTO_TEST_CASE(getCurrentMoveElementIndexTest) {
    const uint8_t zeroElementIndex = 5;
    std::vector<uint8_t> map{1,2,5,3,4,0,6,7,8};
    State s(map, PUZZLE_SIZE);

    BOOST_CHECK(s.getCurrentMoveElementIndex() == zeroElementIndex);
}

BOOST_AUTO_TEST_CASE(getNeighboursTest) {
    std::vector<uint8_t> mapGoodForMoveUp{1,2,5,3,4,6,0,7,8};
    std::vector<uint8_t> afterUp{1,2,5,0,4,6,3,7,8};
    std::vector<uint8_t> afterRight{1,2,5,3,4,6,7,0,8};
    std::vector<std::vector<uint8_t>> possibleMoves{afterUp, afterRight};

    State s1(mapGoodForMoveUp, PUZZLE_SIZE);

    auto neighbours = s1.getNeighbours();
    for (auto neighbour : neighbours) {
        BOOST_CHECK(std::find(possibleMoves.begin(), possibleMoves.end(), neighbour.getMap()) != possibleMoves.end());
    }
}

BOOST_AUTO_TEST_CASE(toStringTest) {
    std::vector<uint8_t> map{1,2,5,3,4,6,0,7,8};
    State s(map, PUZZLE_SIZE);
    std::string stringToCompare = "125\n346\n078";

    BOOST_CHECK(s.toString() == stringToCompare);
}