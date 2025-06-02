//roymeoded2512@gmail.com

#include "MyContainer.hpp"
#include <iostream>

using namespace container;

int main(){

    try{
        MyContainer<int> c;
        
        //Add elements:
        c.addElements(2);
        c.addElements(1);
        c.addElements(4);
        c.addElements(3);

        std::cout << "=== Initial container ===\n";
        std::cout << "Container: " << c << std::endl;
        std::cout << "Size: " << c.size() << "\n";


        //Ascending iteration:
        std::cout<< "Ascending order iteration: ";
        for(auto it=c.ascendingBegin(); it!=c.ascendingEnd();++it){
            std::cout<< *it << " ";
        }
        std::cout<<"\n";

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