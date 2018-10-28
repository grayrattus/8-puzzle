#include <boost/test/unit_test.hpp>

#include "MoveUp.hpp"
#include "State.hpp"
#include "StateCantMoveException.hpp"

const uint8_t PUZZLE_SIZE = 3;

BOOST_AUTO_TEST_CASE(MoveUpTestBasicTest) {
    std::pair<std::vector<uint8_t>, std::vector<uint8_t>> correctPair1 {
        std::vector<uint8_t>{1, 2, 5, 3, 4, 0, 6, 7, 8},
        std::vector<uint8_t>{1, 2, 0, 3, 4, 5, 6, 7, 8 }
    };
    std::pair<std::vector<uint8_t>, std::vector<uint8_t>> correctPair2 {
        std::vector<uint8_t>{1, 2, 5, 3, 0, 4, 6, 7, 8},
        std::vector<uint8_t>{1, 0, 5, 3, 2, 4, 6, 7, 8 }
    };
    std::pair<std::vector<uint8_t>, std::vector<uint8_t>> correctPair3 {
        std::vector<uint8_t>{1, 2, 5, 0, 3, 4, 6, 7, 8},
        std::vector<uint8_t>{0, 2, 5, 1, 3, 4, 6, 7, 8 }
    };
    State* s1 = new State(correctPair1.first, PUZZLE_SIZE);
    State* s2 = new State(correctPair2.first, PUZZLE_SIZE);
    State* s3 = new State(correctPair3.first, PUZZLE_SIZE);
    MoveUp moveUp1(s1);
    MoveUp moveUp2(s2);
    MoveUp moveUp3(s3);

    BOOST_CHECK(moveUp1.move() == correctPair1.second);
    BOOST_CHECK(moveUp2.move() == correctPair2.second);
    BOOST_CHECK(moveUp3.move() == correctPair3.second);

    delete s1;
    delete s2;
    delete s3;
}

BOOST_AUTO_TEST_CASE(MoveUpTestNoMoveUpTests) {
    std::vector<uint8_t> mapGoodForMoveUp{1,2,5,3,4,0,6,7,8};
    std::vector<uint8_t> mapWithNoMoveUp1{0,2,5,3,4,1,6,7,8};
    std::vector<uint8_t> mapWithNoMoveUp2{1,0,5,3,4,1,6,7,8};
    std::vector<uint8_t> mapWithNoMoveUp3{3,2,0,3,4,1,6,7,8};
    State* s1 = new State(mapWithNoMoveUp1, PUZZLE_SIZE);
    State* s2 = new State(mapWithNoMoveUp2, PUZZLE_SIZE);
    State* s3 = new State(mapWithNoMoveUp3, PUZZLE_SIZE);
    State* sGoodForMove = new State(mapGoodForMoveUp, PUZZLE_SIZE);

    MoveUp moveUp1{s1};
    MoveUp moveUp2{s2};
    MoveUp moveUp3{s3};
    MoveUp moveUpGoodForMove{sGoodForMove};

    BOOST_CHECK_THROW(moveUp1.move(), StateCantMoveException);
    BOOST_CHECK_THROW(moveUp2.move(), StateCantMoveException);
    BOOST_CHECK_THROW(moveUp3.move(), StateCantMoveException);
    BOOST_CHECK_NO_THROW(moveUpGoodForMove.move());
}
