#include <iostream>
#include <thread>

using namespace std;
void worker(){
    cout << this_thread::get_id() << endl;
}

int main()
{
    auto worker2 = [] {
        cout << this_thread::get_id() << endl;
    };

    thread t1(worker);
    thread t2([]{ cout << this_thread::get_id() << endl; });
    thread t3(worker2);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}