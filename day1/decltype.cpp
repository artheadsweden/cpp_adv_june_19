#include <iostream>
#include "type.h"
using namespace std;

template <typename T1, typename T2>
auto adder1(T1 a, T2 b) -> decltype(a + b)
{
    return a + b;
}

template <typename T1, typename T2>
auto adder2(T1 a, T2 b)
{
    return a + b;
}

int main()
{
     /*decltype(23 + 34.5) x = 23 + 34.5;
     cout << type_name<decltype(x)>() << endl;
     auto y = adder2(23.4, 34);
     cout << type_name<decltype(y)>() << endl;*/

     int x = 10;
     const int cx = x;

     decltype(cx) b = cx;
     cout << type_name<decltype(b)>() << endl;
     decltype((cx)) c = cx;
     cout << type_name<decltype(c)>() << endl;

     return 0;
}