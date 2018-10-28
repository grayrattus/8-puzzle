#include <boost/test/unit_test.hpp>

#include "MoveLeft.hpp"
#include "State.hpp"
#include "StateCantMoveException.hpp"

const uint8_t PUZZLE_SIZE = 3;

BOOST_AUTO_TEST_CASE(MoveLeftTestBasicTest) {
    std::pair<std::vector<uint8_t>, std::vector<uint8_t>> correctPair1 {
        std::vector<uint8_t>{1, 2, 5, 3, 4, 0, 6, 7, 8},
        std::vector<uint8_t>{1, 2, 5, 3, 0, 4, 6, 7, 8}
    };
    std::pair<std::vector<uint8_t>, std::vector<uint8_t>> correctPair2 {
        std::vector<uint8_t>{1, 2, 5, 3, 0, 4, 6, 7, 8},
        std::vector<uint8_t>{1, 2, 5, 0, 3, 4, 6, 7, 8}
    };
    State* s1 = new State(correctPair1.first, PUZZLE_SIZE);
    State* s2 = new State(correctPair2.first, PUZZLE_SIZE);
    MoveLeft moveLeft1(s1);
    MoveLeft moveLeft2(s2);

    BOOST_CHECK(moveLeft1.move() == correctPair1.second);
    BOOST_CHECK(moveLeft2.move() == correctPair2.second);

    delete s1;
    delete s2;
}

BOOST_AUTO_TEST_CASE(MoveLeftTestNoMoveLeftTests) {
    std::vector<uint8_t> mapGoodForMoveLeft{1,2,5,3,4,0,6,7,8};
    std::vector<uint8_t> mapWithNoMoveLeft1{0,2,5,3,4,1,6,7,8};
    std::vector<uint8_t> mapWithNoMoveLeft2{3,2,5,0,4,1,6,7,8};
    std::vector<uint8_t> mapWithNoMoveLeft3{6,2,5,3,4,1,0,7,8};
    State* s1 = new State(mapWithNoMoveLeft1, PUZZLE_SIZE);
    State* s2 = new State(mapWithNoMoveLeft2, PUZZLE_SIZE);
    State* s3 = new State(mapWithNoMoveLeft3, PUZZLE_SIZE);
    State* sGoodForMove = new State(mapGoodForMoveLeft, PUZZLE_SIZE);

    MoveLeft moveLeft1{s1};
    MoveLeft moveLeft2{s2};
    MoveLeft moveLeft3{s3};
    MoveLeft moveLeftGoodForMove{sGoodForMove};

    BOOST_CHECK_THROW(moveLeft1.move(), StateCantMoveException);
    BOOST_CHECK_THROW(moveLeft2.move(), StateCantMoveException);
    BOOST_CHECK_THROW(moveLeft3.move(), StateCantMoveException);
    BOOST_CHECK_NO_THROW(moveLeftGoodForMove.move());
}
