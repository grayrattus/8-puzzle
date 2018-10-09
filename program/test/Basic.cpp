#include <boost/test/unit_test.hpp>

#include "Basic.hpp"

BOOST_AUTO_TEST_CASE(BasicConstructorTest) {
	Basic* mytest = new Basic();
	BOOST_CHECK_EQUAL(mytest->giveVoice(), "ItsWorking");
}
