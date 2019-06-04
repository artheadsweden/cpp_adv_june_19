#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name = "Anna";
    auto f = [n = move(name)]() {
        cout << "Inside lambda, name = " << n << endl;
    };
    f();
    cout << "Outside lambda, name = " << name << endl;
    return 0;
}