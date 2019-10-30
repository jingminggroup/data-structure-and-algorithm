#include <iostream>
#include "chain.h"

using namespace std;

int main()
{
    cout << "hello world!" << endl;
    chain c;
    c.insert(0, 1);
    c.insert(1, 2);
    c.insert(2, 3);
    c.insert(3, 4);
    c.insert(4, 5);
    c.insert(2, 6);
    c.erase(3);
    c.output();
    
    return 0;
}