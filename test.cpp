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


TEST_CASE("Test reverse order iterator returns reverse insertion order") {
    MyContainer<int> c;
    c.addElements(7);
    c.addElements(15);
    c.addElements(6);
    c.addElements(1);
    c.addElements(2);

    std::vector<int> result;
    for (auto it = c.reverseBegin(); it != c.reverseEnd(); ++it) {
        result.push_back(*it);
    }

    std::vector<int> expected = {2, 1, 6, 15, 7};  // reverse of insertion order
    CHECK(result == expected);
}

TEST_CASE("Test order iterator returns insertion order") {
    MyContainer<int> c;
    c.addElements(7);
    c.addElements(15);
    c.addElements(6);
    c.addElements(1);
    c.addElements(2);

    std::vector<int> result;
    for (auto it = c.orderBegin(); it != c.orderEnd(); ++it) {
        result.push_back(*it);
    }

    std::vector<int> expected = {7, 15, 6, 1, 2};  // insertion order
    CHECK(result == expected);
}

TEST_CASE("Test middle-out iterator with odd number of elements") {
    MyContainer<int> c;
    c.addElements(7);
    c.addElements(15);
    c.addElements(6);
    c.addElements(1);
    c.addElements(2);

    std::vector<int> result;
    for (auto it = c.middleOutBegin(); it != c.middleOutEnd(); ++it) {
        result.push_back(*it);
    }

    std::vector<int> expected = {6, 15, 1, 7, 2};
    CHECK(result == expected);
}

TEST_CASE("Middle-out iterator with even number of elements"){
    MyContainer<int> c;
    c.addElements(10);
    c.addElements(20);
    c.addElements(30);
    c.addElements(40);

    std::vector<int>result;
    for(auto it=c.middleOutBegin(); it!=c.middleOutEnd();++it){
        result.push_back(*it);
    }

    std::vector<int>expected={20,10,30,40};
    CHECK(result==expected);
}

TEST_CASE("All iteratoes on empty container"){
    MyContainer<int>c;

    CHECK(c.size()==0);

    CHECK(c.ascendingBegin() == c.ascendingEnd());
    CHECK(c.descendingBegin() == c.descendingEnd());
    CHECK(c.orderBegin() == c.orderEnd());
    CHECK(c.middleOutBegin() == c.middleOutEnd());
    
}

TEST_CASE("Remove duplicates") {
    MyContainer<int> c;
    c.addElements(4);
    c.addElements(4);
    c.addElements(4);
    c.addElements(5);

    c.remove(4);  //Need to remove every 4

    CHECK(c.size() == 1);
    CHECK_THROWS(c.remove(4));
}

TEST_CASE("Reverse iterator matches reverse of insertion order") {
    MyContainer<int> c;
    std::vector<int> inserted = {8, 6, 9, 3};
    for (int val : inserted) {
        c.addElements(val);
    }

    std::vector<int> reversed;
    for (auto it = c.reverseBegin(); it != c.reverseEnd(); ++it) {
        reversed.push_back(*it);
    }

    std::reverse(inserted.begin(), inserted.end());
    CHECK(reversed == inserted);
}

TEST_CASE("All iterators work correctly after element removal") {
    MyContainer<int> c;
    c.addElements(10);
    c.addElements(5);
    c.addElements(20);
    c.addElements(15);

    c.remove(10);
    c.remove(20);

    std::vector<int> ascending;
    for (auto it = c.ascendingBegin(); it != c.ascendingEnd(); ++it) {
        ascending.push_back(*it);
    }
    CHECK(ascending == std::vector<int>{5, 15});

    std::vector<int> descending;
    for (auto it = c.descendingBegin(); it != c.descendingEnd(); ++it) {
        descending.push_back(*it);
    }
    CHECK(descending == std::vector<int>{15, 5});

    std::vector<int> middle;
    for (auto it = c.middleOutBegin(); it != c.middleOutEnd(); ++it) {
        middle.push_back(*it);
    }
    CHECK(middle == std::vector<int>{5, 15});
}

TEST_CASE("Adding duplicate and removing all of them") {
    MyContainer<int> c;
    c.addElements(1);
    c.addElements(1);
    c.addElements(1);

    CHECK(c.size() == 3);
    c.remove(1); //Need to remove all the elements
    CHECK(c.size() == 0);
}

TEST_CASE("Iterators remain valid after partial removal") {
    MyContainer<int> c;
    c.addElements(5);
    c.addElements(10);
    c.addElements(15);

    c.remove(10);

    std::vector<int> result;
    for (auto it = c.ascendingBegin(); it != c.ascendingEnd(); ++it) {
        result.push_back(*it);
    }

    CHECK(result == std::vector<int>{5, 15});
}

TEST_CASE("Removing from empty container throws") {
    MyContainer<int> c;
    CHECK_THROWS_AS(c.remove(1), std::invalid_argument);
}

TEST_CASE("Mixed positive and negative numbers in iterators") {
    MyContainer<int> c;
    c.addElements(3);
    c.addElements(-5);
    c.addElements(0);
    c.addElements(12);

    std::vector<int> asc;
    for (auto it = c.ascendingBegin(); it != c.ascendingEnd(); ++it) {
        asc.push_back(*it);
    }

    CHECK(asc == std::vector<int>{-5, 0, 3, 12});
}

TEST_CASE("String container ==> insertion and ascending order"){
    MyContainer<std::string> c; 
    c.addElements("delta");
    c.addElements("alpha");
    c.addElements("charles");
    c.addElements("bravo");

    std::vector<std::string> result;
    for(auto it=c.ascendingBegin(); it!=c.ascendingEnd();++it){
        result.push_back(*it);
    }

    std::vector<std::string> expected={"alpha","bravo","charles","delta"};
    CHECK(result==expected);
}

TEST_CASE("String container - remove element and check size") {
    MyContainer<std::string> c;
    c.addElements("foo");
    c.addElements("bar");
    c.remove("foo");

    CHECK(c.size() == 1);
    CHECK_THROWS_AS(c.remove("not_in_container"), std::invalid_argument);
}

TEST_CASE("Double container - insertion and descending order") {
    MyContainer<double> c;
    c.addElements(3.14);
    c.addElements(2.71);
    c.addElements(1.41);
    c.addElements(-1.0);

    std::vector<double> result;
    for (auto it = c.descendingBegin(); it != c.descendingEnd(); ++it) {
        result.push_back(*it);
    }

    std::vector<double> expected = {3.14, 2.71, 1.41, -1.0};
    CHECK(result == expected);
}

TEST_CASE("Double container - middle-out iterator") {
    MyContainer<double> c;
    c.addElements(3.14);
    c.addElements(2.71);
    c.addElements(1.41);
    c.addElements(0.577);
    c.addElements(6.28);

    std::vector<double> result;
    for (auto it = c.middleOutBegin(); it != c.middleOutEnd(); ++it) {
        result.push_back(*it);
    }

    std::vector<double> expected = {1.41, 2.71, 0.577, 3.14, 6.28};
    CHECK(result == expected);
}

TEST_CASE("Double container - remove and exception") {
    MyContainer<double> c;
    c.addElements(1.1);
    c.addElements(2.2);

    c.remove(1.1);
    CHECK(c.size() == 1);

    CHECK_THROWS_AS(c.remove(3.3), std::invalid_argument);
}
