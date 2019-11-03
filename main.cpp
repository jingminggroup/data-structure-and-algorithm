#include <iostream>
#include "chain.cpp"

using namespace std;

int main()
{
    cout << "hello world!" << endl;
    chain<char> c;
    chain<char> d;
    
    c.push_back('a');
    c.push_back('b');
    c.push_back('c');
    c.push_back('d');
    c.push_back('e');
    c.push_back('f');
    c.push_back('g');
    d.push_back('h');
    d.push_back('i');
    d.push_back('j');
    d.push_back('k');
    d.push_back('l');
    chain<char> e = c.melt(d);
    e.output();
    return 0;
}