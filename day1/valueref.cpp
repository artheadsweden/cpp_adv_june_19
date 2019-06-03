#include <iostream>

using namespace std;

void myfunc(int& a)
{
    cout << "a is lvalue" << endl;
}

void myfunc(int&& a)
{
    cout << "a is rvalue" << endl;
}

int main()
{
    int x = 12;
    int y = x;
    myfunc(move(x));
    myfunc(12);
    return 0;
}