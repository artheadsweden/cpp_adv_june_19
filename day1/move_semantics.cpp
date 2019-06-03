#include <iostream>

using namespace std;

class MyClass
{
public:
    MyClass() : x(nullptr)
    {
        cout << "Default constructor" << endl;
    }

    MyClass(int* x_): x(x_)
    {
        cout << "Constructor with argument" << endl;
    }

    MyClass(const MyClass& other): x (other.x)
    {
        cout << "Copy constructor" << endl;
    }

    MyClass(MyClass&& other): x (nullptr)
    {
        swap(x, other.x);
        cout << "Move constructor" << endl;
    }

    MyClass& operator=(const MyClass& other)
    {
        x = other.x;
        cout << "Copy assignment operator" << endl;
        return *this;
    }

    MyClass& operator=(MyClass&& other)
    {
        x = nullptr;
        swap(x, other.x);
        cout << "Move assignment operator" << endl;
        return *this;
    }

private:
    int* x;
};


int main()
{

    return 0;
}