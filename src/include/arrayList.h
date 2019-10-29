#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_
#include "linearList.h"

class arrayList : public linearList
{
    private:
        int* element = nullptr;
        int listSize = 0;
        int arrayLength = 0;
        void checkIndex(int theIndex);
    public:
        // 构造函数，复制构造函数和析构函数
        arrayList(int initialCapacity = 10);
        arrayList(const arrayList&);
        ~arrayList() { delete [] element; };

        //ADT 方法
        bool empty() const;
        int size() const;
        int get(int theIndex);
        int indexOf(const int& theElement) const;
        void erase(int theIndex);
        void insert(int theIndex, const int& theElement);
        void output() const;
};

#endif