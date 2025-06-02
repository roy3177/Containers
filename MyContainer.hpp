//roymeoded2512@gmail.com

#pragma once

#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

namespace container{

/*
The template parameter T defaults to int if not specified.
This means that MyContainer<> is the same as MyContainer<int>.
*/

template<typename T = int>

class MyContainer{
private:
    std::vector<T>elements; //Saves all the elements of the container

public:

    //Method that add element to the container:
    void addElements(const T& value){
        elements.push_back(value); //Add the element to the end of the vector
    }

    //Methof that remove all occurrences of a value from the container:
    void remove(const T& value){
        bool found=false;

        /*
        The std::remove function doesn't actually delete elements from the vector.
        It shifts all elements not equal to value to the front,
        and returns an iterator to the new logical end of the range.
        */
        auto it=std::remove(elements.begin(),elements.end(),value);

        //If our iterator(that return from the remove) is different from the end of the vector:
        if(it!=elements.end()){
            found=true; //We found at least one occurrence
            elements.erase(it,elements.end()); //erase the occurrences of the valuest MyContainer& c) 
        }
        if(!found){
            throw std::invalid_argument("Element not found in our container!");
        }
    }

    //Return the size of the container:
    size_t size() const{
        return elements.size();
    }

    //Method that prints our container:

    /*
    This is a friend method:
    Our method is an external, becaouse of operator >> its by C++ rules (using std::ostream)
    but this operator need access to our elements (our elments are private).
    Thus, our method need to be defined as a friend method ==> gives our external method access to the private elements
    
    */

    friend std::ostream& operator<<(std::ostream& os, const MyContainer& c){
        os << "[";
        for(size_t i=0;i<c.elements.size();i++){
            os<<c.elements[i];
            if(i!=c.elements.size()-1){
                os<< ",";
            }
        }
        os<< "]";
        return os;
    }

    //Method that get copy from the array:
    const std::vector<T>& getElements()const{
        return elements;
    }

};

}