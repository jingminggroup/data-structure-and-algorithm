#include "chain.h"

using namespace std;

void chain::checkIndex(int theIndex)
{
    if (theIndex < 0 || theIndex > this->listSize) {
        throw range_error("out of border");
    }
}

chain::chain()
{
    // the content of the first node is the listsize of this chain
    this->headerNode = new chainNode(this->listSize, nullptr);
}

chain::chain(const chain& theList)
{
    if (theList.listSize != 0) {
        this->listSize = theList.listSize;
        this->headerNode->element = theList.headerNode->element;

        chainNode* sourceNode = this->headerNode;
        chainNode* targetNode = theList.headerNode;
        while (sourceNode->next != nullptr) {
            sourceNode = sourceNode->next;
            chainNode* newNode = new chainNode(sourceNode->element, nullptr);
            targetNode->next = newNode;
            targetNode = targetNode->next;
        }
    } else {
        this->listSize = theList.listSize;
        this->headerNode->element = theList.headerNode->element;
        return ;
    }
}

chain::~chain()
{
    chainNode* currentNode = this->headerNode->next;
    while (currentNode != nullptr) {
        chainNode* deleteNode = currentNode;
        currentNode = currentNode->next;
        delete deleteNode;
    }
}

bool chain::empty() const
{
    if (this->listSize != 0) {
        return false;
    } else {
        return true;
    }
}

int chain::size() const
{
    return this->listSize;
}

int chain::get(int theIndex)
{
    try {
        this->checkIndex(theIndex);
        chainNode* currentNode = this->headerNode;
        int index = 0;
        while (index != theIndex) {
            index++;
            currentNode = currentNode->next;
        }
        return currentNode->element;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return -1;
    }
}

int chain::indexOf(const int& theElement) const
{
    chainNode* currentNode = this->headerNode->next;
    int index = 0;
    while (currentNode != nullptr && currentNode->element == theElement) {
        index++;
    }
    if (currentNode == nullptr) {
        throw "cannot find the element";
    } else {
        return index;
    }
}

void chain::erase(int theIndex)
{
    try {
        this->checkIndex(theIndex);
        int index = 0;
        chainNode* currentNode = this->headerNode;
        while (index != theIndex) {
            currentNode = currentNode->next;
            index++;
        }
        chainNode* deleteNode = currentNode->next;
        currentNode->next = deleteNode->next;
        delete deleteNode;
        deleteNode = nullptr;
        this->listSize--;        
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

void chain::insert(int theIndex, const int& theElement)
{
    try {
        this->checkIndex(theIndex);
        int index = 0;
        chainNode* currentNode = this->headerNode;
        while (index != theIndex) {
            currentNode = currentNode->next;
            index++;
        }
        chainNode* newNode = new chainNode(theElement, currentNode->next);
        currentNode->next = newNode;
        this->listSize++;        
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

void chain::output() const
{
    chainNode* currentNode = this->headerNode->next;
    while (currentNode != nullptr) {
        cout << currentNode->element << " ";
        currentNode = currentNode->next;
    }
}
