#include <boost/test/unit_test.hpp>

#include "State.hpp"
#include "StateCantMoveException.hpp"
#include "BfsSearch.hpp"
#include <vector>
#include <utility>
#include <iostream>


BOOST_AUTO_TEST_CASE(BfsSearchTest) {
    std::vector<uint8_t> result{1,2,3,4,5,6,7,8,0};
    std::vector<uint8_t> map{1,2,3,4,5,0,7,8,6};
    State stateLookedFor(result);
    State initialState(map);

    BfsSearch bfs(initialState, stateLookedFor);
    State st = bfs.performSearch();
    std::cout << st.toString();
}