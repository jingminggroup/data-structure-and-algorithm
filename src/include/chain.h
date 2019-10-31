#ifndef CHAIN_H_
#define CHAIN_H_
#include "linearList.h"

template<typename T>
struct chainNode {
    T element;
    chainNode<T>* next;

    chainNode() {}
    chainNode(T element) {
        this->element = element;
    }
    chainNode(T element, chainNode<T>* next) {
        this->element = element;
        this->next = next;
    }
};

template<typename T>
class chain : public linearList<T>
{
    private:
        int listSize = 0;
        chainNode<T>* headerNode = nullptr;
        void checkIndex(int theIndex);
        chainNode<T>* reverse(chainNode<T>*);
    public:
        chain();
        chain(const chain&);
        ~chain();

        bool empty() const;
        int size() const;
        T get(int theIndex);
        int indexOf(const T& theElement) const;
        void erase(int theIndex);
        void insert(int theIndex, const T& theElement);
        void output() const;
        void setSzie(int theSize);
        void set(int theIndex, const T& theElement);
        void removeRange(int fromIndex, int toIndex);
        int lastIndexOf(const T& theElement);
        const T& operator[](int theIndex);
        bool operator==(const chain<T>&);
        bool operator!=(const chain<T>&);
        bool operator<(const chain<T>&);
        void swap(const chain<T>&);
        void leftShift(int);
        void reverse();
        void reverseRecursive();
};

#endif