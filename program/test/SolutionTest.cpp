#include <boost/test/unit_test.hpp>

#include <boost/thread/thread.hpp> 
#include <boost/chrono.hpp>
#include <iostream> 
#include "Solution.hpp"

BOOST_AUTO_TEST_CASE(SolutionTest) {
    Solution solution;
    std::cout << solution.getExecutionTime();
}
