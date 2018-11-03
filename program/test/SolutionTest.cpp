#include <boost/test/unit_test.hpp>

#include <boost/thread/thread.hpp> 
#include <boost/chrono.hpp>
#include <iostream> 
#include "Solution.hpp"

BOOST_AUTO_TEST_CASE(CheckIncrementations) {
    Solution solution;
    solution.incrementProcessed();
    solution.incrementRecurstionIndex();
    solution.incrementVisited();
    std:string output = "0\n1\n1\n1\n0\n";
    BOOST_CHECK(solution.toString() == output);
}