#include <iostream>
#include "chain.cpp"

using namespace std;

int main()
{
    cout << "hello world!" << endl;
    chain<char> c;
    c.insert(0, 'a');
    c.insert(1, 'b');
    c.insert(2, 'c');
    c.insert(3, 'd');
    c.insert(4, 'e');
    c.insert(5, 'f');
    c.set(2, 'g');
    c.removeRange(1, 4);
    c.output();
    
    return 0;
}