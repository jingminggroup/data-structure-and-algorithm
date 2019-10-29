#ifndef LINEARLIST_H_
#define LINEARLIST_H_
#include <iostream>

class linearList
{
private:
    /* data */
public:
    virtual ~linearList() {};
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual int get(int theIndex) = 0;
    virtual int indexOf(const int& theElement) const = 0;
    virtual void erase(int theIndex) = 0;
    virtual void insert(int theIndex, const int& theElement) = 0;
    virtual void output() const = 0;
};

#endif