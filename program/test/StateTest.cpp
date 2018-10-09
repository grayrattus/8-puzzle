#include <boost/test/unit_test.hpp>

#include "State.hpp"
#include "StateCantMoveException.hpp"
#include <vector>
#include <utility>
#include <iostream>


BOOST_AUTO_TEST_CASE(StateConstructorTest) {
    std::vector<uint8_t> map{1,2,5,3,4,0,6,7,8};
    State s(map);
    State s1(map);

    BOOST_CHECK(s == s1);
    BOOST_CHECK(s == map);
}

BOOST_AUTO_TEST_CASE(getCurrentMoveElementIndexTest) {
    const uint8_t zeroElementIndex = 5;
    std::vector<uint8_t> map{1,2,5,3,4,0,6,7,8};
    State s(map);

    BOOST_CHECK(s.getCurrentMoveElementIndex() == zeroElementIndex);
}

BOOST_AUTO_TEST_CASE(moveUpTestBasicTest) {
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
    State s1(correctPair1.first);
    BOOST_CHECK(s1.moveUp() == correctPair1.second);
    State s2(correctPair2.first);
    BOOST_CHECK(s2.moveUp() == correctPair2.second);
    State s3(correctPair3.first);
    BOOST_CHECK(s3.moveUp() == correctPair3.second);
}

BOOST_AUTO_TEST_CASE(moveUpTestNoMoveUpTests) {
    std::vector<uint8_t> mapGoodForMoveUp{1,2,5,3,4,0,6,7,8};
    std::vector<uint8_t> mapWithNoMoveUp1{0,2,5,3,4,1,6,7,8};
    std::vector<uint8_t> mapWithNoMoveUp2{1,0,5,3,4,1,6,7,8};
    std::vector<uint8_t> mapWithNoMoveUp3{3,2,0,3,4,1,6,7,8};
    State s1(mapWithNoMoveUp1);
    State s2(mapWithNoMoveUp2);
    State s3(mapWithNoMoveUp3);
    State sGoodForMove(mapGoodForMoveUp);

    BOOST_CHECK_THROW(s1.moveUp(), StateCantMoveException);
    BOOST_CHECK_THROW(s2.moveUp(), StateCantMoveException);
    BOOST_CHECK_THROW(s3.moveUp(), StateCantMoveException);
    BOOST_CHECK_NO_THROW(sGoodForMove.moveUp());
}

BOOST_AUTO_TEST_CASE(moveDownTestBasicTest) {
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
    State s1(correctPair1.first);
    BOOST_CHECK(s1.moveDown() == correctPair1.second);
    State s2(correctPair2.first);
    BOOST_CHECK(s2.moveDown() == correctPair2.second);
    State s3(correctPair3.first);
    BOOST_CHECK(s3.moveDown() == correctPair3.second);
}

BOOST_AUTO_TEST_CASE(moveDownTestNoMoveDownTests) {
    std::vector<uint8_t> mapGoodForMoveDown{1,2,5,3,4,0,6,7,8};
    std::vector<uint8_t> mapWithNoMoveDown1{6,2,5,3,4,1,0,7,8};
    std::vector<uint8_t> mapWithNoMoveDown2{6,2,5,3,4,1,7,0,8};
    std::vector<uint8_t> mapWithNoMoveDown3{6,2,5,3,4,1,8,7,0};
    State s1(mapWithNoMoveDown1);
    State s2(mapWithNoMoveDown2);
    State s3(mapWithNoMoveDown3);
    State sGoodForMove(mapGoodForMoveDown);

    BOOST_CHECK_THROW(s1.moveDown(), StateCantMoveException);
    BOOST_CHECK_THROW(s2.moveDown(), StateCantMoveException);
    BOOST_CHECK_THROW(s3.moveDown(), StateCantMoveException);
    BOOST_CHECK_NO_THROW(sGoodForMove.moveDown());
}

BOOST_AUTO_TEST_CASE(moveLeftTestBasicTest) {
    std::pair<std::vector<uint8_t>, std::vector<uint8_t>> correctPair1 {
        std::vector<uint8_t>{1, 2, 5, 3, 4, 0, 6, 7, 8},
        std::vector<uint8_t>{1, 2, 5, 3, 0, 4, 6, 7, 8}
    };
    std::pair<std::vector<uint8_t>, std::vector<uint8_t>> correctPair2 {
        std::vector<uint8_t>{1, 2, 5, 3, 0, 4, 6, 7, 8},
        std::vector<uint8_t>{1, 2, 5, 0, 3, 4, 6, 7, 8}
    };
    State s1(correctPair1.first);
    BOOST_CHECK(s1.moveLeft() == correctPair1.second);
    State s2(correctPair2.first);
    BOOST_CHECK(s2.moveLeft() == correctPair2.second);
}

BOOST_AUTO_TEST_CASE(moveLeftTestNoMoveLeftTests) {
    std::vector<uint8_t> mapGoodForMoveLeft{1,2,5,3,4,0,6,7,8};
    std::vector<uint8_t> mapWithNoMoveLeft1{0,2,5,3,4,1,6,7,8};
    std::vector<uint8_t> mapWithNoMoveLeft2{3,2,5,0,4,1,6,7,8};
    std::vector<uint8_t> mapWithNoMoveLeft3{6,2,5,3,4,1,0,7,8};
    State s1(mapWithNoMoveLeft1);
    State s2(mapWithNoMoveLeft2);
    State s3(mapWithNoMoveLeft3);
    State sGoodForMove(mapGoodForMoveLeft);

    BOOST_CHECK_THROW(s1.moveLeft(), StateCantMoveException);
    BOOST_CHECK_THROW(s2.moveLeft(), StateCantMoveException);
    BOOST_CHECK_THROW(s3.moveLeft(), StateCantMoveException);
    BOOST_CHECK_NO_THROW(sGoodForMove.moveLeft());
}

BOOST_AUTO_TEST_CASE(moveRightTestBasicTest) {
    std::pair<std::vector<uint8_t>, std::vector<uint8_t>> correctPair1 {
        std::vector<uint8_t>{1, 2, 5, 3, 4, 6, 0, 7, 8},
        std::vector<uint8_t>{1, 2, 5, 3, 4, 6, 7, 0, 8}
    };
    std::pair<std::vector<uint8_t>, std::vector<uint8_t>> correctPair2 {
        std::vector<uint8_t>{1, 2, 5, 3, 7, 4, 6, 0, 8},
        std::vector<uint8_t>{1, 2, 5, 3, 7, 4, 6, 8, 0}
    };
    State s1(correctPair1.first);
    BOOST_CHECK(s1.moveRight() == correctPair1.second);
    State s2(correctPair2.first);
    BOOST_CHECK(s2.moveRight() == correctPair2.second);
}

BOOST_AUTO_TEST_CASE(moveRightTestNoMoveRightTests) {
    std::vector<uint8_t> mapGoodForMoveRight{1,2,5,3,4,6,0,7,8};
    std::vector<uint8_t> mapWithNoMoveRight1{5,2,0,3,4,1,6,7,8};
    std::vector<uint8_t> mapWithNoMoveRight2{1,2,5,3,4,0,6,7,8};
    std::vector<uint8_t> mapWithNoMoveRight3{8,2,5,3,4,1,6,7,0};
    State s1(mapWithNoMoveRight1);
    State s2(mapWithNoMoveRight2);
    State s3(mapWithNoMoveRight3);
    State sGoodForMove(mapGoodForMoveRight);

    BOOST_CHECK_THROW(s1.moveRight(), StateCantMoveException);
    BOOST_CHECK_THROW(s2.moveRight(), StateCantMoveException);
    BOOST_CHECK_THROW(s3.moveRight(), StateCantMoveException);
    BOOST_CHECK_NO_THROW(sGoodForMove.moveRight());
}