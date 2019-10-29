#include "arrayList.h"
#include <iostream>
#include <exception>
#include <string.h>

using namespace std;

void arrayList::checkIndex(int theIndex)
{
    if (theIndex < 0 || theIndex > this->listSize) {
        throw range_error("out of border");
    }
}

void arrayList::extend()
{
    this->arrayLength *= 2;
    int* temp = new int[this->arrayLength];
    memset(temp, 0, arrayLength);
    memcpy(temp, this->element, (this->listSize)*sizeof(int));
    delete [] element;
    element = temp; 
    temp = nullptr;
}

arrayList::arrayList(int initialCapacity)
{
    this->element = new int[initialCapacity];
    if (this->element == nullptr) {
        throw "null ptr exception";
    }
    this->listSize = 0;
    this->arrayLength = initialCapacity;
    memset(this->element, 0, this->listSize);
}

arrayList::arrayList(const arrayList& newArrayList)
{
    if (this->element != nullptr)
    {
        memcpy(newArrayList.element, this->element, this->listSize);
    }
}

bool arrayList::empty() const
{
    if (this->listSize == 0) {
        return true;
    } else {
        return false;
    }
}

int arrayList::size() const
{
    return this->listSize;
}

int arrayList::get(int theIndex)
{
    try {
        this->checkIndex(theIndex);
    } catch(const std::exception& e) {
        std::cerr << "Exception:" << " " << __FILE__ << " " << __func__ << " " << __LINE__ << " " << e.what() << '\n';
    }
    return this->element[theIndex];
}

int arrayList::indexOf(const int& theElement) const
{
    int index = 0;
    for (index = 0; index < this->listSize; index++) {
        if (this->element[index] == theElement) {
            break;
        }
    }
    if (index == this->listSize) {
        return -1;
    } else {
        return index;
    }
}

void arrayList::erase(int theIndex)
{
    try {
        this->checkIndex(theIndex);
        memcpy(this->element+theIndex, this->element+theIndex+1, (this->listSize-1-theIndex)*sizeof(int));
        this->listSize--;
    } catch(const std::exception& e) {
        std::cerr << "Exception:" << " " << __FILE__ << " " << __func__ << " " << __LINE__ << " " << e.what() << '\n';
    }
}

void arrayList::insert(int theIndex, const int& theElement)
{
    if (this->listSize == this->arrayLength) {
        this->extend();
    }
    if (this->listSize != 0) {
        try {
            this->checkIndex(theIndex);
            memmove(this->element+theIndex+1, this->element+theIndex, (this->listSize-theIndex)*sizeof(int));
        } catch(const std::exception& e) {
            std::cerr << "Exception:" << " " << __FILE__ << " " << __func__ << " " << __LINE__ << " " << e.what() << '\n';
        }
    }
    this->element[theIndex] = theElement;
    this->listSize++;
}

void arrayList::output() const
{
    if (this->listSize == 0) {
        cout << "the array list is empty" << endl;
        return ;
    }
    for (int index = 0; index < this->listSize; index++) {
        cout << this->element[index] << " ";
    }
    cout << endl;
}
