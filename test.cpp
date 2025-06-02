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