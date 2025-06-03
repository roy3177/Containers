//roymeoded2512@gmail.com

#include "MyContainer.hpp"
#include <iostream>

using namespace container;

template<typename Iterator>
//Method for printing iterators:
void printIterator(const std::string& label, Iterator begin, Iterator end){
    std::cout << label << ": ";
    for(auto it = begin; it != end; ++it){
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

int main(){

    MyContainer<int> firstContainer;
    firstContainer.addElements(7);
    firstContainer.addElements(211);
    firstContainer.addElements(6);
    firstContainer.addElements(1);
    firstContainer.addElements(-12);
    firstContainer.addElements(14);
    firstContainer.addElements(10);
    firstContainer.addElements(9);

    std::cout << "============= First container =============\n";
    std::cout << "\nContainer: " << firstContainer << std::endl;
    std::cout << "Size: " << firstContainer.size() << "\n";
    printIterator("MiddleOut order", firstContainer.middleOutBegin(), firstContainer.middleOutEnd());
    std::cout << "\n";

    MyContainer<int> secondContainer;
    secondContainer.addElements(77);
    secondContainer.addElements(14);
    secondContainer.addElements(4);
    secondContainer.addElements(33);

    std::cout << "============= Second container =============\n";
    std::cout << "\nContainer: " << secondContainer << std::endl;
    std::cout << "Size: " << secondContainer.size() << "\n";

    // Print all iterator types
    printIterator("Ascending order", secondContainer.ascendingBegin(), secondContainer.ascendingEnd());
    printIterator("Descending order", secondContainer.descendingBegin(), secondContainer.descendingEnd());
    printIterator("SideCross order", secondContainer.sideCrossBegin(), secondContainer.sideCrossEnd());
    printIterator("Reverse order", secondContainer.reverseBegin(), secondContainer.reverseEnd());
    printIterator("Insertion order", secondContainer.orderBegin(), secondContainer.orderEnd());
    printIterator("MiddleOut order", secondContainer.middleOutBegin(), secondContainer.middleOutEnd());

    std::cout << "\n";

    // Remove element
    std::cout << "\nRemoving element 4...\n";
    secondContainer.remove(4);
    std::cout << "Our container now after we remove 4 is : " << secondContainer << std::endl;
    std::cout << "Size: " << secondContainer.size() << "\n";
    printIterator("Ascending after removal", secondContainer.ascendingBegin(), secondContainer.ascendingEnd());
    std::cout << "\n";

    // Try to remove nonexistent element (handled locally)
    std::cout << "\nAttempting to remove element 333...\n";
    try {
        secondContainer.remove(333);
    } catch(const std::exception& e) {
        std::cerr << "Exception caught while removing element: " << e.what() << "\n";
    }

    std::cout << "\n";

    MyContainer<std::string> words;
    words.addElements("delta");
    words.addElements("alpha");
    words.addElements("echo");
    words.addElements("charlie");
    words.addElements("bravo");

    std::cout << "============= Third container =============\n";
    std::cout << "\nContainer: " << words << std::endl;
    std::cout << "Size: " << words.size() << "\n";

    printIterator("Ascending order", words.ascendingBegin(), words.ascendingEnd());
    printIterator("Descending order", words.descendingBegin(), words.descendingEnd());
    printIterator("SideCross order", words.sideCrossBegin(), words.sideCrossEnd());
    printIterator("Reverse order", words.reverseBegin(), words.reverseEnd());
    printIterator("Insertion order", words.orderBegin(), words.orderEnd());
    printIterator("MiddleOut order", words.middleOutBegin(), words.middleOutEnd());

    std::cout << "\nRemoving element 'alpha'...\n";
    words.remove("alpha");
    std::cout << "Updated container: " << words << "\n";
    std::cout << "Size: " << words.size() << "\n";
    printIterator("MiddleOut after removal", words.middleOutBegin(), words.middleOutEnd());
    std::cout << "\n";

    std::cout << "============= Fourth container (empty) =============\n";
    MyContainer<double> empty;
    std::cout << "\n";

    std::cout << "Container: " << empty << "\n";
    std::cout << "Size: " << empty.size() << "\n";
    printIterator("Ascending order", empty.ascendingBegin(), empty.ascendingEnd());
    printIterator("MiddleOut order", empty.middleOutBegin(), empty.middleOutEnd());

    std::cout << "\nTrying to remove from empty container...\n";
    try {
        empty.remove(3.14);
    } catch(const std::exception& e) {
        std::cerr << "Exception caught while removing from empty: " << e.what() << "\n";
        std::cout << "\n";
    }

    std::cout << "============= Fifth container (doubles) =============\n";
    MyContainer<double> doubles;

    doubles.addElements(3.14);
    doubles.addElements(2.71);
    doubles.addElements(1.41);
    doubles.addElements(0.577);
    doubles.addElements(6.28);
    doubles.addElements(-1.0);

    std::cout << "\nContainer: " << doubles << "\n";
    std::cout << "Size: " << doubles.size() << "\n";

    printIterator("Ascending order", doubles.ascendingBegin(), doubles.ascendingEnd());
    printIterator("Descending order", doubles.descendingBegin(), doubles.descendingEnd());
    printIterator("SideCross order", doubles.sideCrossBegin(), doubles.sideCrossEnd());
    printIterator("Reverse order", doubles.reverseBegin(), doubles.reverseEnd());
    printIterator("Insertion order", doubles.orderBegin(), doubles.orderEnd());
    printIterator("MiddleOut order", doubles.middleOutBegin(), doubles.middleOutEnd());

    std::cout << "\nRemoving element 2.71...\n";
    doubles.remove(2.71);
    std::cout << "Updated container: " << doubles << "\n";
    std::cout << "Size: " << doubles.size() << "\n";

    printIterator("MiddleOut after removal", doubles.middleOutBegin(), doubles.middleOutEnd());
    std::cout << "\n";

    return 0;
}
