#include "chain.h"

using namespace std;

template<typename T>
void chain<T>::checkIndex(int theIndex)
{
    if(this->listSize != 0) {
        if (theIndex < 0 || theIndex >= this->listSize) {
            throw range_error("out of border");
        }        
    }
}

template<typename T>
chain<T>::chain()
{
    // the content of the first node is the listsize of this chain
    this->headerNode = new chainNode<T>(this->listSize, nullptr);
}

template<typename T>
chain<T>::chain(const chain& theList)
{
    if (theList.listSize != 0) {
        this->listSize = theList.listSize;
        this->headerNode->element = theList.headerNode->element;

        chainNode<T>* sourceNode = this->headerNode;
        chainNode<T>* targetNode = theList.headerNode;
        while (sourceNode->next != nullptr) {
            sourceNode = sourceNode->next;
            chainNode<T>* newNode = new chainNode<T>(sourceNode->element, nullptr);
            targetNode->next = newNode;
            targetNode = targetNode->next;
        }
    } else {
        this->listSize = theList.listSize;
        this->headerNode->element = theList.headerNode->element;
        return ;
    }
}

template<typename T>
chain<T>::~chain()
{
    chainNode<T>* currentNode = this->headerNode->next;
    while (currentNode != nullptr) {
        chainNode<T>* deleteNode = currentNode;
        currentNode = currentNode->next;
        delete deleteNode;
    }
}

template<typename T>
bool chain<T>::empty() const
{
    if (this->listSize != 0) {
        return false;
    } else {
        return true;
    }
}

template<typename T>
int chain<T>::size() const
{
    return this->listSize;
}

template<typename T>
T chain<T>::get(int theIndex)
{
    try {
        this->checkIndex(theIndex);
        chainNode<T>* currentNode = this->headerNode;
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

template<typename T>
int chain<T>::indexOf(const T& theElement) const
{
    chainNode<T>* currentNode = this->headerNode->next;
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

template<typename T>
void chain<T>::erase(int theIndex)
{
    try {
        this->checkIndex(theIndex);
        int index = 0;
        chainNode<T>* currentNode = this->headerNode;
        while (index != theIndex) {
            currentNode = currentNode->next;
            index++;
        }
        chainNode<T>* deleteNode = currentNode->next;
        currentNode->next = deleteNode->next;
        delete deleteNode;
        deleteNode = nullptr;
        this->listSize--;        
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

template<typename T>
void chain<T>::insert(int theIndex, const T& theElement)
{
    try {
        if (theIndex < 0 || theIndex > this->listSize) {
            throw range_error("out of border");
        }     
        int index = 0;
        chainNode<T>* currentNode = this->headerNode;
        while (index != theIndex) {
            currentNode = currentNode->next;
            index++;
        }
        chainNode<T>* newNode = new chainNode<T>(theElement, currentNode->next);
        currentNode->next = newNode;
        this->listSize++;        
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

template<typename T>
void chain<T>::output() const
{
    chainNode<T>* currentNode = this->headerNode->next;
    while (currentNode != nullptr) {
        cout << currentNode->element << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
}

// P124 2
template<typename T>
void chain<T>::setSzie(int theSize)
{
    int index = 0;
    if (this->listSize <= theSize) {
        return ;
    } else {
        chainNode<T>* deleteNode = nullptr;
        chainNode<T>* currentNode = this->headerNode;
        while (index < theSize) {
            currentNode = currentNode->next;
            index++;
        }
        deleteNode = currentNode->next;
        currentNode->next = nullptr;
        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
            delete deleteNode;
            deleteNode = currentNode;
        }
    }
}

// P124 3
template<typename T>
void chain<T>::set(int theIndex, const T& theElement)
{
    int index = 0;
    try {
        this->checkIndex(theIndex);
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    chainNode<T>* currentNode = this->headerNode;
    while (index <= theIndex) {
        currentNode = currentNode->next;
        index++;
    }
    currentNode->element = theElement;
}

// P124 4
template<typename T>
void chain<T>::removeRange(int fromIndex, int toIndex)
{
    chainNode<T>* fromIndexNode = this->headerNode;
    chainNode<T>* toIndexNode = this->headerNode;
    try {
        this->checkIndex(fromIndex);
        this->checkIndex(toIndex);
    } catch (std::exception e) {
        cerr << e.what() << endl;
    }
    int index = 0;
    while (index < fromIndex) {
        fromIndexNode = fromIndexNode->next;
        index++;
    }
    toIndexNode = fromIndexNode;
    while (index <= toIndex) {
        toIndexNode = toIndexNode->next;
        index++;
    }
    chainNode<T>* deleteNode = fromIndexNode->next;
    chainNode<T>* currentNode = deleteNode;
    fromIndexNode->next = nullptr;
    while (currentNode != toIndexNode) {
        currentNode = currentNode->next;
        delete deleteNode;
        deleteNode = currentNode;
        this->listSize--;
    }
    fromIndexNode->next = currentNode->next;
    delete currentNode;
}

// P124 5
template<typename T>
int chain<T>::lastIndexOf(const T& theElement)
{
    int index = 0, lastIndex = -1;
    chainNode<T>* currentNode = this->headerNode->next;
    while (currentNode != nullptr) {
        if (currentNode->element == theElement) {
            lastIndex = index;
        }        
        currentNode = currentNode->next;
        index++;
    }
    return lastIndex;
}

// P124 6
template<typename T>
const T& chain<T>::operator[](int theIndex)
{
    try {
        this->checkIndex(theIndex);
    } catch(const std::exception& e) {
        std::cerr << e.what() << endl;
    }
    int index = 0;
    chainNode<T>* currentNode = this->headerNode->next;
    while (index != theIndex) {
        currentNode = currentNode->next;
        index++;
    }
    return currentNode->element;
}

// P124 7
template<typename T>
bool chain<T>::operator==(const chain<T>& secondChain)
{
    if (this->listSize != secondChain.listSize) {
        return false;
    } else {
        chainNode<T>* firstCurrentNode = this->headerNode->next;
        chainNode<T>* secondCurrentNode = secondChain.headerNode->next;
        while (firstCurrentNode != nullptr && secondCurrentNode != nullptr) {
            if (firstCurrentNode->element != secondCurrentNode->element) {
                return false;
            } else {
                firstCurrentNode = firstCurrentNode->next;
                secondCurrentNode = secondCurrentNode->next;
            }
        }
    }
    return true;
}

// P124 8
template<typename T>
bool chain<T>::operator!=(const chain<T>& secondChain)
{
    return ~this->operator==(secondChain);
}

// P124 9
template<typename T>
bool chain<T>::operator<(const chain<T>& secondChain)
{

    chainNode<T>* firstCurrentNode = this->headerNode->next;
    chainNode<T>* secondCurrentNode = secondChain.headerNode->next;
    while (firstCurrentNode != nullptr && secondCurrentNode != nullptr) {
        if (firstCurrentNode->element > secondCurrentNode->element) {
            return false;
        } else {
            firstCurrentNode = firstCurrentNode->next;
            secondCurrentNode = secondCurrentNode->next;
        }
    }
    if (secondCurrentNode == nullptr && firstCurrentNode != nullptr) {
        return false;
    } else {
        return true;
    }
}

// P124 10
template<typename T>
void chain<T>::swap(const chain<T>& theChain)
{
    try {
        if (this->listSize != theChain.listSize) {
            throw "the length of the two chain is not equal";
        }
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    chainNode<T>* firstCurrentNode = this->headerNode->next;
    chainNode<T>* secondCurrentNode = theChain.headerNode->next;
    while (firstCurrentNode != nullptr && secondCurrentNode != nullptr) {
        T tmp;
        tmp = firstCurrentNode->element;
        firstCurrentNode->element = secondCurrentNode->element;
        secondCurrentNode->element = tmp;
        firstCurrentNode = firstCurrentNode->next;
        secondCurrentNode = secondCurrentNode->next;
    }
}

// P124 14
template<typename T>
void chain<T>::leftShift(int value)
{
    try{
        this->checkIndex(value);
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    int index = 0;
    chain<T> tmp;
    chainNode<T>* dstNode = this->headerNode->next;
    chainNode<T>* srcNode = this->headerNode->next;
    while (index != value) {
        tmp.insert(tmp.listSize, srcNode->element);
        srcNode = srcNode->next;
        index++;
    }
    while (srcNode != nullptr) {
        dstNode->element = srcNode->element;
        dstNode = dstNode->next;
        srcNode = srcNode->next;
    }
    srcNode = tmp.headerNode->next;
    while (srcNode != nullptr) {
        dstNode->element = srcNode->element;
        dstNode = dstNode->next;
        srcNode = srcNode->next;
    }
}

// P124 15
template<typename T>
void chain<T>::reverse()
{
    chainNode<T>* preNode = nullptr;
    chainNode<T>* curNode = this->headerNode->next;
    chainNode<T>* nxtNode = curNode->next;
    while (curNode != nullptr) {
        curNode->next = preNode;
        preNode = curNode;
        curNode = nxtNode;
        if (nxtNode != nullptr) {
            nxtNode = nxtNode->next;
        }
    }
    this->headerNode->next = preNode;
}

template<typename T>
chainNode<T>* chain<T>::reverse(chainNode<T>* curNode)
{
    if (curNode->next == nullptr) {
        this->headerNode->next = curNode;
        return curNode;
    } else {
        chainNode<T>* node = this->reverse(curNode->next);
        node->next = curNode;
        return curNode;
    }
}

template<typename T>
void chain<T>::reverseRecursive()
{
    this->reverse(this->headerNode->next)->next = nullptr;
}

// P124 2
template<typename T>
void chain<T>::setSzie(int theSize)
{
    int index = 0;
    if (this->listSize <= theSize) {
        return ;
    } else {
        chainNode<T>* deleteNode = nullptr;
        chainNode<T>* currentNode = this->headerNode;
        while (index < theSize) {
            currentNode = currentNode->next;
            index++;
        }
        deleteNode = currentNode->next;
        currentNode->next = nullptr;
        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
            delete deleteNode;
            deleteNode = currentNode;
        }
    }
}

// P124 3
template<typename T>
void chain<T>::set(int theIndex, const T& theElement)
{
    int index = 0;
    try {
        this->checkIndex(theIndex);
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    chainNode<T>* currentNode = this->headerNode;
    while (index <= theIndex) {
        currentNode = currentNode->next;
        index++;
    }
    currentNode->element = theElement;
}

// P124 4
template<typename T>
void chain<T>::removeRange(int fromIndex, int toIndex)
{
    chainNode<T>* fromIndexNode = this->headerNode;
    chainNode<T>* toIndexNode = this->headerNode;
    try {
        this->checkIndex(fromIndex);
        this->checkIndex(toIndex);
    } catch (std::exception e) {
        cerr << e.what() << endl;
    }
    int index = 0;
    while (index < fromIndex) {
        fromIndexNode = fromIndexNode->next;
        index++;
    }
    toIndexNode = fromIndexNode;
    while (index <= toIndex) {
        toIndexNode = toIndexNode->next;
        index++;
    }
    chainNode<T>* deleteNode = fromIndexNode->next;
    chainNode<T>* currentNode = deleteNode;
    fromIndexNode->next = nullptr;
    while (currentNode != toIndexNode) {
        currentNode = currentNode->next;
        delete deleteNode;
        deleteNode = currentNode;
        this->listSize--;
    }
    fromIndexNode->next = currentNode->next;
    delete currentNode;
}

// P124 5
template<typename T>
int chain<T>::lastIndexOf(const T& theElement)
{
    int index = 0, lastIndex = -1;
    chainNode<T>* currentNode = this->headerNode->next;
    while (currentNode != nullptr) {
        if (currentNode->element == theElement) {
            lastIndex = index;
        }        
        currentNode = currentNode->next;
        index++;
    }
    return lastIndex;
}

// P124 6
template<typename T>
const T& chain<T>::operator[](int theIndex)
{
    try {
        this->checkIndex(theIndex);
    } catch(const std::exception& e) {
        std::cerr << e.what() << endl;
    }
    int index = 0;
    chainNode<T>* currentNode = this->headerNode->next;
    while (index != theIndex) {
        currentNode = currentNode->next;
        index++;
    }
    return currentNode->element;
}

// P124 7
template<typename T>
bool chain<T>::operator==(const chain<T>& secondChain)
{
    if (this->listSize != secondChain.listSize) {
        return false;
    } else {
        chainNode<T>* firstCurrentNode = this->headerNode->next;
        chainNode<T>* secondCurrentNode = secondChain.headerNode->next;
        while (firstCurrentNode != nullptr && secondCurrentNode != nullptr) {
            if (firstCurrentNode->element != secondCurrentNode->element) {
                return false;
            } else {
                firstCurrentNode = firstCurrentNode->next;
                secondCurrentNode = secondCurrentNode->next;
            }
        }
    }
    return true;
}

// P124 8
template<typename T>
bool chain<T>::operator!=(const chain<T>& secondChain)
{
    return ~this->operator==(secondChain);
}
