#ifndef CHAIN_H_
#define CHAIN_H_
#include "linearList.h"

struct chainNode {
    int element;
    chainNode* next;

    chainNode() {}
    chainNode(int element) {
        this->element = element;
    }
    chainNode(int element, chainNode* next) {
        this->element = element;
        this->next = next;
    }
};

class chain : public linearList
{
    private:
        int listSize = 0;
        chainNode* headerNode = nullptr;
        void checkIndex(int theIndex);
    public:
        chain();
        chain(const chain&);
        ~chain();

        bool empty() const;
        int size() const;
        int get(int theIndex);
        int indexOf(const int& theElement) const;
        void erase(int theIndex);
        void insert(int theIndex, const int& theElement);
        void output() const;
};

#endif