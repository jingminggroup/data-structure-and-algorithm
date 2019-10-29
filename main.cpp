#include <iostream>
#include "arrayList.h"

using namespace std;

int main()
{
    cout << "hello world!" << endl;
    arrayList array;
    array.insert(0, 1);
    array.insert(1, 2);
    array.insert(2, 3);
    array.insert(3, 4);
    array.insert(4, 5);
    array.insert(5, 6);
    array.insert(6, 7);
    array.insert(7, 8);
    array.insert(8, 9);
    array.insert(9, 10);
    array.insert(10, 11);
    array.output();
    array.erase(12);
    return 0;
}