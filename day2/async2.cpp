#include <iostream>
#include <vector>
#include <future>
#include <numeric>
using namespace std;

int accumulate_block_value(int* data, size_t count)
{
    accumulate(data, data + count, 0);
}

int main()
{
    vector<int> v1 {1, 2, 3, 4, 5};
    vector<int> v2 {6, 7, 8, 9, 10};
    future<int> result1(async(accumulate_block_value, v1.data(), v1.size()));
    future<int> result2(async(launch::async, accumulate_block_value, v1.data(), v1.size()));
    cout << result1.get() << endl;
    cout << result2.get() << endl;
    return 0;
}