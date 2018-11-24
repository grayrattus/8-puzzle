#include <boost/test/unit_test.hpp>

#include "State.hpp"
#include "StateCantMoveException.hpp"
#include "DfsSearch.hpp"
#include <vector>
#include <utility>
#include <iostream>


const uint8_t PUZZLE_SIZE = 4;
const std::string FIRST_MOVES = "UDLR";


BOOST_AUTO_TEST_CASE(BfsSearchTest) {
    std::vector<uint8_t> map{1,2,3,4,
                             5,6,7,8,
                             9,0,11,12,
                             13,10,14,15};
    std::vector<uint8_t> result{1,2,3,4,
                                5,6,7,8,
                                9,10,11,12,
                                13,14,15,0};

    State stateLookedFor(result, PUZZLE_SIZE, FIRST_MOVES);
    State initialState(map, PUZZLE_SIZE, FIRST_MOVES);

    DfsSearch bfs(initialState, stateLookedFor);
    Solution st = bfs.performSearch();
    std::cout << st.toString();
    std::cout << st.getMoves();
}