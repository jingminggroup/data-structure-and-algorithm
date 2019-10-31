#include "arrayList.h"
#include <iostream>
#include <exception>
#include <string.h>

using namespace std;

template<typename T>
void arrayList<T>::checkIndex(int theIndex)
{
    if (theIndex < 0 || theIndex > this->listSize) {
        throw range_error("out of border");
    }
}

template<typename T>
void arrayList<T>::extend()
{
    this->arrayLength *= 2;
    T* temp = new T[this->arrayLength];
    memset(temp, 0, arrayLength);
    memcpy(temp, this->element, (this->listSize)*sizeof(T));
    delete [] element;
    element = temp; 
    temp = nullptr;
}

template<typename T>
arrayList<T>::arrayList(int initialCapacity)
{
    this->element = new T[initialCapacity];
    if (this->element == nullptr) {
        throw "null ptr exception";
    }
    this->listSize = 0;
    this->arrayLength = initialCapacity;
    memset(this->element, 0, (this->listSize)*sizeof(T));
}

template<typename T>
arrayList<T>::arrayList(const arrayList& newArrayList)
{
    if (this->element != nullptr)
    {
        memcpy(newArrayList.element, this->element, (this->listSize)*sizeof(T));
    }
}

template<typename T>
bool arrayList<T>::empty() const
{
    if (this->listSize == 0) {
        return true;
    } else {
        return false;
    }
}

template<typename T>
int arrayList<T>::size() const
{
    return this->listSize;
}

template<typename T>
T arrayList<T>::get(int theIndex)
{
    try {
        this->checkIndex(theIndex);
    } catch(const std::exception& e) {
        std::cerr << "Exception:" << " " << __FILE__ << " " << __func__ << " " << __LINE__ << " " << e.what() << '\n';
    }
    return this->element[theIndex];
}

template<typename T>
int arrayList<T>::indexOf(const T& theElement) const
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

template<typename T>
void arrayList<T>::erase(int theIndex)
{
    try {
        this->checkIndex(theIndex);
        memcpy(this->element+theIndex, this->element+theIndex+1, (this->listSize-1-theIndex)*sizeof(T));
        this->listSize--;
    } catch(const std::exception& e) {
        std::cerr << "Exception:" << " " << __FILE__ << " " << __func__ << " " << __LINE__ << " " << e.what() << '\n';
    }
}

template<typename T>
void arrayList<T>::insert(int theIndex, const T& theElement)
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

template<typename T>
void arrayList<T>::output() const
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
