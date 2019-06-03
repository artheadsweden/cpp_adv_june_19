#include <iostream>
#include "type.h"

using namespace std;

template <typename T>
void myfunc(T&& a)
{
    cout << "a is " << type_name<decltype(a)>() << endl;
}

int main()
{
    int x = 10;
    myfunc(move(x));
    myfunc(10);
    return 0;
}