#include "arrayList.h"
#include <iostream>
#include <exception>
#include <string.h>

using namespace std;

void arrayList::checkIndex(int theIndex)
{
    if (theIndex < 0 || theIndex > this->arrayLength) {
        throw "out of border";
    }
}

void arrayList::extend()
{
    this->arrayLength *= 2;
    int* temp = new int[arrayLength];
    memset(temp, 0, arrayLength);
    memcpy(temp, this->element, this->listSize);
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
    this->checkIndex(theIndex);
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
    this->checkIndex(theIndex);
    for (int index = theIndex; index < this->listSize-theIndex; index++) {
        this->element[index] = this->element[index+1];
    }
    this->listSize--;
}

void arrayList::insert(int theIndex, const int& theElement)
{
    if (this->listSize == this->arrayLength) {
        this->extend();
    }
    if (this->listSize != 0) {
        this->checkIndex(theIndex);
        for (int index = this->listSize-1; index >= theIndex; index--) {
            this->element[index+1] = this->element[index];
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
