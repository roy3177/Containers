//roymeoded2512@gmail.com

#include "MyContainer.hpp"
#include <iostream>

using namespace container;

int main(){

    try{


        container::MyContainer<int> mc;
        mc.addElements(7);
        mc.addElements(15);
        mc.addElements(6);
        mc.addElements(1);
        mc.addElements(2);


        std::cout << "============= First container =============\n";
        std::cout << "Container: " << mc << std::endl;
        std::cout << "Size: " << mc.size() << "\n";

        for (auto it = mc.middleOutBegin(); it != mc.middleOutEnd(); ++it) {
            std::cout << *it << " ";
        }
        std::cout<<"\n";


        MyContainer<int> c;
        
        //Add elements:
        c.addElements(2);
        c.addElements(1);
        c.addElements(4);
        c.addElements(3);

        std::cout << "============= Second container =============\n";
        std::cout << "Container: " << c << std::endl;
        std::cout << "Size: " << c.size() << "\n";


        //Ascending iteration:
        std::cout<< "Ascending order iteration: ";
        for(auto it=c.ascendingBegin(); it!=c.ascendingEnd();++it){
            std::cout<< *it << " ";
        }
        std::cout<<"\n";

        //Descending iteration:
        std::cout << "Descending order iteration: ";
        for (auto it = c.descendingBegin(); it != c.descendingEnd(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        //SideCross iteration:
        std::cout << "SideCross order iteration: ";
        for (auto it = c.sideCrossBegin(); it != c.sideCrossEnd(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        //Reverse order iteration:
        std::cout << "Reverse order iteration: ";
        for (auto it = c.reverseBegin(); it != c.reverseEnd(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        //Order iteration (insertion order):
        std::cout << "Order iteration (insertion order): ";
        for (auto it = c.orderBegin(); it != c.orderEnd(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        
        //Remove elements:
        std::cout << "\nRemoving element 2...\n";
        c.remove(2);
        std::cout<< "Our container now after we remove 2 is : " << c << std::endl;
        std::cout << "Size: " << c.size() << "\n";

        std::cout << "Ascending order after removal: ";
        for (auto it = c.ascendingBegin(); it != c.ascendingEnd(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "\n";

        //Try to remove element that not in our continer-->throw exception:
        std::cout << "\nAttempting to remove element 333...\n";
        c.remove(333);
    }

    catch(const std::exception& e){
        std::cerr << "Exception caught while removing element: " << e.what() << std::endl;
    }

    return 0;
}