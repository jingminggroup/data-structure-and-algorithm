#include <iostream>
#include "arrayList.h"

using namespace std;

int main()
{
    cout << "hello world!" << endl;
    arrayList array;
    array.output();
    array.insert(0, 1);
    array.output();
    array.insert(1, 2);
    array.output();
    array.insert(2, 3);
    array.insert(3, 4);
    array.insert(4, 5);
    array.output();
    array.erase(0);
    array.output();
    array.erase(1);
    array.output();
    array.erase(2);
    array.output();
    array.insert(2, 3);
    array.insert(3, 4);
    array.insert(4, 5);
    array.output();
    cout << array.indexOf(3) << endl;
    return 0;
}