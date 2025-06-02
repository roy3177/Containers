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


    /*
    ********AscendingIterator********
    This iterator allows iterating over the elements of MyContainer in ascending order.
    For example: if our container is [5,2,7] , our iterator will yield 2,5,7
    */

    class AscendingIterator{

    private:

        std::vector<T> sorted_elements;
        size_t index;

    public:
        
        //Constructor:
        AscendingIterator(const MyContainer& container){
            sorted_elements=container.getElements();
            std::sort(sorted_elements.begin(),sorted_elements.end());
            index=0;
        }

        //Returns the current value the iterator is pointing to:
        T operator*() const{
            return sorted_elements[index];
        }

        //Moves the iterator to the next element:
        AscendingIterator& operator++(){
            ++index; //Increase the index to move to the next element
            return *this;
        }

        //Check wether two iteratoes are at different positions:
        bool operator!=(const AscendingIterator& other)const{
            return index!=other.index;
        }

        //Returns the number of elements in the sorted container:
        size_t size() const {
            return sorted_elements.size();
        }


        void setToEnd() {
            index = sorted_elements.size();
        }

    };

     /*
    ********DescendingIterator********
    This iterator allows iterating over the elements of MyContainer from the largest
    to the smallest elmenet.
    For example:if our container holds [3,7,1] , the iterator will yield 7,3,1.
    */

    class DescendingIterator{
    
    private:

        std::vector<T> sorted_elements;
        size_t index;

    public:
        
        //Constructor:
        DescendingIterator(const MyContainer& container){
            sorted_elements=container.getElements();
            std::sort(sorted_elements.begin(),sorted_elements.end(), std::greater<T>());
            index=0;
        }

        //Returns the current value the iterator is pointing to:
        T operator*() const{
            return sorted_elements[index];
        }


        //Moves the iterator to the next element:
        DescendingIterator& operator++(){
            ++index; //Increase the index to move to the next element
            return *this;
        }


        //Check wether two iteratoes are at different positions:
        bool operator!=(const DescendingIterator& other)const{
            return index!=other.index;
        }


        //Returns the number of elements in the sorted container:
        size_t size() const {
            return sorted_elements.size();
        }

        // Move iterator to end
        void setToEnd() {
            index = sorted_elements.size();
        }

    };

    //Returns an AscendingIterator pointing to the beginning:
    AscendingIterator ascendingBegin() const{
        return AscendingIterator(*this);
    }

    //Returns an AscendingIterator pointing to the end:
    AscendingIterator ascendingEnd() const{
        AscendingIterator it(*this);
        it.setToEnd();
        return it;
    }

    //Returns a DescendingIterator pointing to the beginning:
    DescendingIterator descendingBegin() const{
        return DescendingIterator(*this);
    }

    //Returns a DescendingIterator pointing to the end:
    DescendingIterator descendingEnd() const{
        DescendingIterator it(*this);
        it.setToEnd();
        return it;
    }

};


}