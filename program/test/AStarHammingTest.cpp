#include <boost/test/unit_test.hpp>

#include "State.hpp"
#include "StateCantMoveException.hpp"
#include "AStarHamming.hpp"
#include <vector>
#include <utility>
#include <iostream>


const uint8_t PUZZLE_SIZE = 4;
const std::string FIRST_MOVES = "RDUL";


BOOST_AUTO_TEST_CASE(AStarHammingTest) {
    std::vector<uint8_t> map{1, 2, 3, 4,
                             5, 6, 11, 7,
                             9, 10, 15, 8,
                             13, 14, 0, 12};

    std::vector<uint8_t> result{1, 2, 3, 4,
               5, 6, 7, 8,
               9, 10, 11, 12,
               13, 14, 15, 0};

    State stateLookedFor(result, PUZZLE_SIZE, FIRST_MOVES);
    State initialState(map, PUZZLE_SIZE, FIRST_MOVES);

    AStarHamming a(initialState, stateLookedFor);
    Solution st = a.performSearch();
    std::cout << st.toString();
    std::cout << st.getMoves();
}