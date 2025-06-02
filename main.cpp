//roymeoded2512@gmail.com

#include "MyContainer.hpp"
#include <iostream>

using namespace container;

int main(){

    try{
        MyContainer<int> c;
        
        //Add elements:
        c.addElements(1);
        c.addElements(2);
        c.addElements(3);
        c.addElements(4);

        //Print our container:
        std::cout<< "Our initial container is : " << c << std::endl;

        //Remove elements:
        c.remove(2);
        
        std::cout<< "Our container now after we remove 2 is : " << c << std::endl;

        //Print size of the container:
        std::cout << "The size of the container is : " << c.size() << std::endl;

        //Try to remove element that not in our continer-->throw exception:
        c.remove(333);
    }

    catch(const std::exception& e){
        std::cerr<< "Exception: " << e.what() << std::endl;
    }

    return 0;
}