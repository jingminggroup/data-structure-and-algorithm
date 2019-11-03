#ifndef EXTENDLINEARLIST_H_
#define EXTENDLINEARLIST_H_
#include "linearList.h"

template<typename T>
class extendLinearList : public linearList<T>
{
    public:
        virtual ~extendLinearList() {}
        virtual void clear() = 0;
        virtual void push_back(const T& theElement) = 0;
};
#endif