#include <iostream>

using namespace std;

int main()
{
    auto x = 10;
    auto f = [&r = x]() { r++; };
    f();
    cout << x << endl;
    return 0;
}