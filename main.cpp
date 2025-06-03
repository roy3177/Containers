//roymeoded2512@gmail.com

#include "MyContainer.hpp"
#include <iostream>

using namespace container;

template<typename Iterator>

//Method for printing iterators:
void printIterator(const std::string& label, Iterator begin, Iterator end){
    std::cout<<label<<": ";
    for(auto it=begin;it!=end;++it){
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";
}

int main(){

    try{

        MyContainer<int>firstContainer;
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
        std::cout<<"\n";


        MyContainer<int>secondContainer;
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

        std::cout<<"\n";

        
        //Remove elements:
        std::cout << "\nRemoving element 4...\n";
        secondContainer.remove(4);
        std::cout<< "Our container now after we remove 4 is : " << secondContainer << std::endl;
        std::cout << "Size: " << secondContainer.size() << "\n";

        printIterator("Ascending after removal", secondContainer.ascendingBegin(), secondContainer.ascendingEnd());
        std::cout << "\n";

        //Try to remove element that not in our continer-->throw exception:
        std::cout << "\nAttempting to remove element 333...\n";
        secondContainer.remove(333);
    }

    catch(const std::exception& e){
        std::cerr << "Exception caught while removing element: " << e.what() << std::endl;
         std::cout<<"\n";
    }

           
    return 0;
}