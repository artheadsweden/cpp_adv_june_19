#include <iostream>
#include <thread>
#include <functional>
#include <chrono>

using namespace std;

class ThreadWrapper
{
public:
    explicit ThreadWrapper(function<void()> f) {
        t = new thread(f);
    }
    ~ThreadWrapper()
    {
        if (t->joinable())
        {
            t->join();
            cout << "Joined" << endl;
        }
        delete t;
    }
    ThreadWrapper(const ThreadWrapper&) = delete;
    ThreadWrapper& operator =(const ThreadWrapper&) = delete;
private:
    thread* t;
};

int main()
{
    {
        ThreadWrapper tw1([]{
            cout << "Hi from thread" << endl;
            this_thread::sleep_for(chrono::seconds(5));
        });
        ThreadWrapper tw2([]{
            cout << "Hi from thread" << endl;
            this_thread::sleep_for(chrono::seconds(2));
        });
        cout << "Thread is going" << endl;
    }

    cout << "Thread is done" << endl;
    return 0;
}