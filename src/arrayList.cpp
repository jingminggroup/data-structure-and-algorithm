#include "arrayList.h"
#include <iostream>
#include <exception>
#include <string.h>

using namespace std;

void arrayList::checkIndex(int theIndex)
{
    if (theIndex < 0 || theIndex > this->listSize) {
        throw "out of border";
    }
}

arrayList::arrayList(int initialCapacity)
{
    this->element = new int[initialCapacity];
    if (this->element == nullptr) {
        throw "null ptr exception";
    }
    this->listSize = initialCapacity;
    this->arrayLength = this->listSize;
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
    memcpy(this->element+theIndex, this->element+theIndex+1, this->listSize-1-theIndex);
    this->listSize--;
}

void arrayList::insert(int theIndex, const int& theElement)
{
    this->checkIndex(theIndex);
    memmove(this->element+theIndex+1, this->element+theIndex, this->listSize-theIndex);
    this->listSize++;
}

void arrayList::output() const
{
    for (int index = 0; index < this->listSize; index++) {
        cout << this->element[index] << " ";
    }
}
