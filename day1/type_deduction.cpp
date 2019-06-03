#include <iostream>
#include <vector>
#include "type.h"

using namespace std;

template <typename T>
void f_ref(T& param)
{
    cout << "T is " << type_name<T>() << endl;
    cout << "param is " << type_name<decltype(param)>() << endl;
}

template <typename T>
void f_const_ref(const T& param)
{
    cout << "T is " << type_name<T>() << endl;
    cout << "param is " << type_name<decltype(param)>() << endl;
}

template <typename T>
void f_pointer(T* param)
{
    cout << "T is " << type_name<T>() << endl;
    cout << "param is " << type_name<decltype(param)>() << endl;
}

template <typename T>
void f_universal(T&& param)
{
    cout << "T is " << type_name<T>() << endl;
    cout << "param is " << type_name<decltype(param)>() << endl;
}

template <typename T>
void f_value(T param)
{
    cout << "T is " << type_name<T>() << endl;
    cout << "param is " << type_name<decltype(param)>() << endl;
}

template <typename T>
void f_array1(T param[])
{
    cout << "T is " << type_name<T>() << endl;
    cout << "param is " << type_name<decltype(param)>() << endl;
}


template <typename T>
void f_array2(T& param)
{
    cout << "T is " << type_name<T>() << endl;
    cout << "param is " << type_name<decltype(param)>() << endl;
}
int main()
{
    int x = 10;
    const int cx = x;
    const int& rx = x;

    cout << "====================" << endl;
    cout << "T& param" << endl;
    cout << "====================" << endl;
    f_ref(x);   // T = int, param = int&
    f_ref(cx);  // T = const int, param const int&
    f_ref(rx);  // T = const int, param const int&

    cout << "====================" << endl;
    cout << "const T& param" << endl;
    cout << "====================" << endl;
    f_const_ref(x);   // T = int, param = const int&
    f_const_ref(cx);  // T = int, param const int&
    f_const_ref(rx);  // T = int, param const int&


    cout << "====================" << endl;
    cout << "T* param" << endl;
    cout << "====================" << endl;
    const int* pcx = &x;

    f_pointer(&x);  // T = int, param int*
    f_pointer(pcx); // T = const int, param const int*


    cout << "====================" << endl;
    cout << "T&& param" << endl;
    cout << "====================" << endl;
    f_universal(x);   // T = int&, param = int&
    f_universal(cx);  // T = const int&, param = const int&
    f_universal(rx);  // T = const int&, param = const int&
    f_universal(34);  // T = int, param = int&&


    cout << "====================" << endl;
    cout << "T param" << endl;
    cout << "====================" << endl;
    f_value(x);   // T = int, param = int
    f_value(cx);  // T = int, param = int
    f_value(rx);  // T = int, param = int
    f_value(pcx); // T = const int*, param = const int*

    auto& v1 = x;  // auto = int, v1 = int&
    auto& v2 = cx; // auto = const int, v2 const int&
    auto& v3 = rx; // auto = const int, v3 const int&

    cout << type_name<decltype(v1)>() << endl;
    cout << type_name<decltype(v2)>() << endl;
    cout << type_name<decltype(v3)>() << endl;


    auto a1{ 1 };  // a1 = int
    cout << type_name<decltype(a1)>() << endl;
    auto a2 = { 2 };  // a2 = std::initializer_list<int>
    cout << type_name<decltype(a2)>() << endl;
    auto a3 = { 1, 2, 3 };  // a3 = std::initializer_list<int>
    cout << type_name<decltype(a3)>() << endl;
    //auto a4 { 1, 2, 3 };  // ERROR


    int arr[]{ 1, 2, 3 };

    cout << "====================" << endl;
    cout << "T param[]" << endl;
    cout << "====================" << endl;
    f_array1(arr); // T = int, param = int*


    cout << "====================" << endl;
    cout << "T& param" << endl;
    cout << "====================" << endl;
    f_array2(arr);  // T = int [3], param = int(&)[3]


    return 0;
}