#include <iostream>
#include "chain.cpp"

using namespace std;

int main()
{
    cout << "hello world!" << endl;
    chain<char> c;
    chain<char> d;
    c.insert(0, 'a');
    c.insert(1, 'b');
    c.insert(2, 'c');
    c.insert(3, 'd');
    c.insert(4, 'a');
    c.insert(5, 'd');
    d.insert(0, 'a');
    d.insert(1, 'b');
    d.insert(2, 'c');
    d.insert(3, 'd');
    d.insert(4, 'a');
    d.insert(5, 'k');
    c.output();
    if (c != d) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}