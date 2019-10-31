#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_
#include "linearList.h"

template<typename T>
class arrayList : public linearList<T>
{
    private:
        T* element = nullptr;
        int listSize = 0;
        int arrayLength = 0;
        void checkIndex(int theIndex);
        void extend();
    public:
        // 构造函数，复制构造函数和析构函数
        arrayList(int initialCapacity = 10);
        arrayList(const arrayList&);
        ~arrayList() { delete [] element; };

        //ADT 方法
        bool empty() const;
        int size() const;
        T get(int theIndex);
        int indexOf(const T& theElement) const;
        void erase(int theIndex);
        void insert(int theIndex, const T& theElement);
        void output() const;
};

#endif