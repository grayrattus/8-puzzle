#include <boost/test/unit_test.hpp>

#include "State.hpp"
#include "StateCantMoveException.hpp"
#include "AStarHamming.hpp"
#include <vector>
#include <utility>
#include <iostream>


const uint8_t PUZZLE_SIZE = 3;
const std::string FIRST_MOVES = "UDLR";


BOOST_AUTO_TEST_CASE(AStarHammingTest) {
    std::vector<uint8_t> result{1,2,3,4,5,6,7,8,0};
    std::vector<uint8_t> map{1,0,2,4,5,3,7,8,6};

    State stateLookedFor(result, PUZZLE_SIZE, FIRST_MOVES);
    State initialState(map, PUZZLE_SIZE, FIRST_MOVES);

    AStarHamming bfs(initialState, stateLookedFor);
    Solution st = bfs.performSearch();
    std::cout << st.toString();
    std::cout << st.getMoves();
}