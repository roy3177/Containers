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

    /*
    ********SideCrossIterator********
    This iterator allows iterating over the elements of MyContainer in a zigzag or 
    "slide cross" order.
    First , it yields the smalledt element, then the largest, then the second smallest,
    then the second largest, and so on=>alternating from both ends of the sorted container inward.
    For example:if our container holds [3,7,77,11,10,6,4,2,1] , the iterator will 
    yield: 1,77,2,11,3,10,4,7,6
    */

    class SideCrossIterator{
    
    private:
        std::vector<T> sorted_elements;
        size_t left;
        size_t right;
        bool isLeftTurn; //true if it take from the left, false if it take from the right

    public:
        
        //Constructor:
        SideCrossIterator(const MyContainer& container)
            :sorted_elements(container.getElements()), left(0) ,isLeftTurn(true){
            std::sort(sorted_elements.begin(), sorted_elements.end());
            right=sorted_elements.size()-1;
        }

        //Returns the current value the iterator is pointing to:
        T operator*()const{
            return isLeftTurn ? sorted_elements[left] : sorted_elements[right];
        }

        // Prefix increment
        SideCrossIterator& operator++() {
            //If we passed all the elements:
            if (left > right){
                return *this; // Already at end
            }

            //Left turn:
            if (isLeftTurn) {
                ++left;
            }
                
            //Right turn:
            else {
                --right;
            }
                
            //flip the side:
            isLeftTurn = !isLeftTurn;
            return *this;
        }

        // Inequality operator
        //If left>right=>we finish scan the elements:
        bool operator!=(const SideCrossIterator& ) const {
            return left <= right;
        }

        // Move iterator to end
        void setToEnd() {
            left=sorted_elements.size();
            right=0;
        }
    };

     /*
    ********ReverseOrderIterator ********
    This iterator scans the container in reverse insertion order.
    For example, if the elements were inserted as [7,15,6,1,2] , the iterator will
    yield 2,1,6,15,7
    */

    class ReverseOrderIterator{

    private:
        const std::vector<T>& original_elements;
        size_t index;
    
    public:

        //Constructor: receives the original vector by reference
        ReverseOrderIterator(const MyContainer& container)
            : original_elements(container.getElements()),
             index(container.size() ? container.size() - 1 : 0) {}

        //Returns the current value the iterator is pointing to:
        T operator*() const {
            return original_elements[index];
        }

        // Prefix increment:
        ReverseOrderIterator& operator++(){

            //If we did not came to the start of the bector==>move down the index by one:
            if(index>0){
                --index;
            }
            else{
                index=static_cast<size_t>(-1); //save the first elment==>for show that we are at the end of the scanning.
            }
            return *this;
        }

        // checks if iterators are at different positions:
        bool operator!=(const ReverseOrderIterator& other)const{
            return index!=other.index;
        }

        size_t getIndex() const {
            return index;
        }

        //Indicate that the iterator is at the end of the iteration stage:
        void setToEnd() {
            index = static_cast<size_t>(-1);
        }
    };

    
      /*
    ********OrderIterator********
    This iterator is a simple iterator that scans the conntainer in the original
    order in which the elements were inserted.
    For example, if the container contains [1,2,4,5], then iterating with OrderIterator
    will return the elements in that same order 1,2,4,5
    */

    class OrderIterator{

    private:
        const std::vector<T>& original_elements;
        size_t index;

    public:

        //Constructor:
        OrderIterator(const MyContainer& container)
        : original_elements(container.getElements()), index(0) {}


        //Returns the current value the iterator is pointing to:
        T operator*() const {
            return original_elements[index];
        }

        // Prefix increment
        OrderIterator& operator++() {
            ++index;
            return *this;
        }

        // checks if iterators are at different positions:
        bool operator!=(const OrderIterator& other)const{
            return index!=other.index;
        }

        // Set to end
        void setToEnd() {
            index = original_elements.size();
        }
    };


     /*
    ********MiddleOutOrderIterator********
    This iterator scans the container from the middle outward:
    It starts with the middle element of the container,then it alternates:
    one step to the left of the middle(-1), then one step to the right of the middle(+1), and
    continues this alternating pattern until all the elements are visited.
    For example, given the container [7,15,6,1,2] , the iteration order : 6,15,1,7,2
    */

    class MiddleOutOrderIterator{

    private:
        const std::vector<T>& elements;
        std::vector<size_t> accessOrder; //Index list that introduce the access order.
        size_t index;
    
    public:

        //Constructor:
        MiddleOutOrderIterator(const MyContainer& container):
            elements(container.getElements()), index(0){
            size_t n=elements.size();

            //If the container is empty:
            if(n==0){
                return;
            }

            //Compute the middle of the vector:
            //If the element is even=>starting with the left element between the two:
            size_t mid=n/2;
            if(n%2==0){
                mid--;
            }

            //Adding the index of the middle element as the first in the accessOrder:
            accessOrder.push_back(mid);

            //Loop that visited all the distances from the middle to outside:
            for(size_t offset=1;offset<=mid || mid+offset<n;++offset){
                if (mid >= offset){
                    accessOrder.push_back(mid - offset);
                }

                if (mid + offset < n){ 
                    accessOrder.push_back(mid + offset);
                }
            }       
        }

        //Returns the current value the iterator is pointing to:
        T operator*()const{
            if(index>=accessOrder.size()){
                throw std::out_of_range("Moddleout iterator out of range"); 
            }

            return elements[accessOrder[index]];
        }

        // Prefix increment:
        MiddleOutOrderIterator& operator++() {
            ++index;
            return *this;
        }

        // checks if iterators are at different positions:
        bool operator!=(const MiddleOutOrderIterator& other) const {
            return index != other.index;
        }

        void setToEnd() {
            index = accessOrder.size();
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

    //Returns a SideCrossIterator pointing to the beginning:
    SideCrossIterator sideCrossBegin() const {
        return SideCrossIterator(*this);
    }

    //Returns a SideCrossIterator pointing to the end:
    SideCrossIterator sideCrossEnd() const {
        SideCrossIterator it(*this);
        it.setToEnd();
        return it;
    }

    // Begin for reverse iterator
    ReverseOrderIterator reverseBegin() const {
        return ReverseOrderIterator(*this);
    }

    // End for reverse iterator
    ReverseOrderIterator reverseEnd() const {
        ReverseOrderIterator it(*this);
        it.setToEnd();
        return it;
    }
    
    OrderIterator orderBegin() const {
        return OrderIterator(*this);
    }

    OrderIterator orderEnd() const {
        OrderIterator it(*this);
        it.setToEnd();
        return it;
    }

    // Begin for MiddleOutOrderIterator
    MiddleOutOrderIterator middleOutBegin() const {
        return MiddleOutOrderIterator(*this);
    }

    // End for MiddleOutOrderIterator
    MiddleOutOrderIterator middleOutEnd() const {
        MiddleOutOrderIterator it(*this);
        it.setToEnd();
        return it;
    }


};


}