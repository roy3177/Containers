//roymeoded2512@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.hpp"
#include <sstream>

using namespace container;

TEST_CASE("Test addElement and size"){
    MyContainer<int> c;
    c.addElements(1);
    c.addElements(2);
    CHECK(c.size()==2);
}


TEST_CASE("Test remove single element") {
    MyContainer<int> c;
    c.addElements(5);
    c.addElements(7);
    c.remove(5);
    CHECK(c.size() == 1);
}

TEST_CASE("Test remove throws on non-existent element") {
    MyContainer<int> c;
    c.addElements(10);
    CHECK_THROWS_AS(c.remove(99), std::invalid_argument);
}

TEST_CASE("Test ascending iterator returns sorted order") {
    MyContainer<int> c;
    c.addElements(9);
    c.addElements(3);
    c.addElements(7);

    std::vector<int> result;
    for (auto it = c.ascendingBegin(); it != c.ascendingEnd(); ++it) {
        result.push_back(*it);
    }

    CHECK(result == std::vector<int>{3, 7, 9});
}

TEST_CASE("Test descending iterator returns sorted order(from biggest to smallest)") {
    MyContainer<int> c;
    c.addElements(9);
    c.addElements(3);
    c.addElements(12);
    c.addElements(133);

    std::vector<int> result;
    std::vector<int>expected={133,12,9,3};
    for (auto it = c.descendingBegin(); it != c.descendingEnd(); ++it) {
        result.push_back(*it);
    }

    CHECK(result == expected);

}


TEST_CASE("Test descending iterator returns sorted order(from biggest to smallest)-->with duplicate values") {
    MyContainer<int> c;
    c.addElements(9);
    c.addElements(3);
    c.addElements(7);
    c.addElements(7);
    c.addElements(12);
    c.addElements(133);

    std::vector<int> result;
    std::vector<int>expected={133,12,9,7,7,3};
    for (auto it = c.descendingBegin(); it != c.descendingEnd(); ++it) {
        result.push_back(*it);
    }

    CHECK(result == expected);

}


TEST_CASE("Test side cross iterator zigzag order") {
    MyContainer<int> c;
    c.addElements(7);
    c.addElements(1);
    c.addElements(2);
    c.addElements(15);
    c.addElements(6);

    std::vector<int> result;
    for (auto it = c.sideCrossBegin(); it != c.sideCrossEnd(); ++it) {
        result.push_back(*it);
    }

    std::vector<int> expected = {1, 15, 2, 7, 6}; // zigzag order
    CHECK(result == expected);
}


