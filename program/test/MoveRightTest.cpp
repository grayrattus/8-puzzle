#include <boost/test/unit_test.hpp>

#include "MoveRight.hpp"
#include "State.hpp"
#include "StateCantMoveException.hpp"

const uint8_t PUZZLE_SIZE = 3;

BOOST_AUTO_TEST_CASE(MoveRightTestBasicTest) {
    std::pair<std::vector<uint8_t>, std::vector<uint8_t>> correctPair1 {
        std::vector<uint8_t>{1, 2, 5, 3, 4, 6, 0, 7, 8},
        std::vector<uint8_t>{1, 2, 5, 3, 4, 6, 7, 0, 8}
    };
    std::pair<std::vector<uint8_t>, std::vector<uint8_t>> correctPair2 {
        std::vector<uint8_t>{1, 2, 5, 3, 7, 4, 6, 0, 8},
        std::vector<uint8_t>{1, 2, 5, 3, 7, 4, 6, 8, 0}
    };
    State* s1 = new State(correctPair1.first, PUZZLE_SIZE);
    State* s2 = new State(correctPair2.first, PUZZLE_SIZE);
    MoveRight moveRight1(s1);
    MoveRight moveRight2(s2);

    BOOST_CHECK(moveRight1.move() == correctPair1.second);
    BOOST_CHECK(moveRight2.move() == correctPair2.second);

    delete s1;
    delete s2;
}

BOOST_AUTO_TEST_CASE(MoveRightTestNoMoveRightTests) {
    std::vector<uint8_t> mapGoodForMoveRight{1,2,5,3,4,6,0,7,8};
    std::vector<uint8_t> mapWithNoMoveRight1{5,2,0,3,4,1,6,7,8};
    std::vector<uint8_t> mapWithNoMoveRight2{1,2,5,3,4,0,6,7,8};
    std::vector<uint8_t> mapWithNoMoveRight3{8,2,5,3,4,1,6,7,0};
    State* s1 = new State(mapWithNoMoveRight1, PUZZLE_SIZE);
    State* s2 = new State(mapWithNoMoveRight2, PUZZLE_SIZE);
    State* s3 = new State(mapWithNoMoveRight3, PUZZLE_SIZE);
    State* sGoodForMove = new State(mapGoodForMoveRight, PUZZLE_SIZE);

    MoveRight moveRight1{s1};
    MoveRight moveRight2{s2};
    MoveRight moveRight3{s3};
    MoveRight moveRightGoodForMove{sGoodForMove};

    BOOST_CHECK_THROW(moveRight1.move(), StateCantMoveException);
    BOOST_CHECK_THROW(moveRight2.move(), StateCantMoveException);
    BOOST_CHECK_THROW(moveRight3.move(), StateCantMoveException);
    BOOST_CHECK_NO_THROW(moveRightGoodForMove.move());
}
