#include <boost/test/unit_test.hpp>

#include "MoveDown.hpp"
#include "State.hpp"
#include "StateCantMoveException.hpp"

const uint8_t PUZZLE_SIZE = 3;

BOOST_AUTO_TEST_CASE(MoveDownTestBasicTest) {
    std::pair<std::vector<uint8_t>, std::vector<uint8_t>> correctPair1 {
        std::vector<uint8_t>{1, 2, 5, 3, 4, 0, 6, 7, 8},
        std::vector<uint8_t>{1, 2, 5, 3, 4, 8, 6, 7, 0}
    };
    std::pair<std::vector<uint8_t>, std::vector<uint8_t>> correctPair2 {
        std::vector<uint8_t>{1, 2, 5, 3, 0, 4, 6, 7, 8},
        std::vector<uint8_t>{1, 2, 5, 3, 7, 4, 6, 0, 8}
    };
    std::pair<std::vector<uint8_t>, std::vector<uint8_t>> correctPair3 {
        std::vector<uint8_t>{1, 2, 5, 0, 4, 3, 6, 7, 8},
        std::vector<uint8_t>{1, 2, 5, 6, 4, 3, 0, 7, 8}
    };
    State* s1 = new State(correctPair1.first, PUZZLE_SIZE);
    State* s2 = new State(correctPair2.first, PUZZLE_SIZE);
    State* s3 = new State(correctPair3.first, PUZZLE_SIZE);
    MoveDown moveDown1(s1);
    MoveDown moveDown2(s2);
    MoveDown moveDown3(s3);

    BOOST_CHECK(moveDown1.move() == correctPair1.second);
    BOOST_CHECK(moveDown2.move() == correctPair2.second);
    BOOST_CHECK(moveDown3.move() == correctPair3.second);

    delete s1;
    delete s2;
    delete s3;
}

BOOST_AUTO_TEST_CASE(MoveDownTestNoMoveDownTests) {
    std::vector<uint8_t> mapGoodForMoveDown{1,2,5,3,4,0,6,7,8};
    std::vector<uint8_t> mapWithNoMoveDown1{6,2,5,3,4,1,0,7,8};
    std::vector<uint8_t> mapWithNoMoveDown2{6,2,5,3,4,1,7,0,8};
    std::vector<uint8_t> mapWithNoMoveDown3{6,2,5,3,4,1,8,7,0};
    State* s1 = new State(mapWithNoMoveDown1, PUZZLE_SIZE);
    State* s2 = new State(mapWithNoMoveDown2, PUZZLE_SIZE);
    State* s3 = new State(mapWithNoMoveDown3, PUZZLE_SIZE);
    State* sGoodForMove = new State(mapGoodForMoveDown, PUZZLE_SIZE);

    MoveDown moveDown1{s1};
    MoveDown moveDown2{s2};
    MoveDown moveDown3{s3};
    MoveDown moveDownGoodForMove{sGoodForMove};

    BOOST_CHECK_THROW(moveDown1.move(), StateCantMoveException);
    BOOST_CHECK_THROW(moveDown2.move(), StateCantMoveException);
    BOOST_CHECK_THROW(moveDown3.move(), StateCantMoveException);
    BOOST_CHECK_NO_THROW(moveDownGoodForMove.move());
}
