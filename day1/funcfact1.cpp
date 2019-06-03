#include <iostream>

using namespace std;

int main()
{
    int x = 10;
    int y = 19;

    auto func = [&](int a, int b)
            {
                return a + b + x + y;
            };

    cout << func(1, 2) << endl;

    x = 3;
    y = 4;
    cout << func(1, 2) << endl;


    return 0;
}