#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
using namespace std;
mutex cout_mutex;

class Worker
{
public:
    Worker(string n) : name(n){}

    void operator()()
    {
        for(int i = 0; i <= 3; i++)
        {
            this_thread::sleep_for(chrono::seconds(1));
            {
              lock_guard<mutex> cout_lock(cout_mutex);
              cout << name << " is doing work " << i << endl;
            }
        }
    }
private:
    string name;
};

int main()
{
    cout << "Boss says: Strat working" << endl;
    thread bob(Worker("Bob"));
    thread sara(Worker("Sara"));
    thread tom(Worker("Tom"));
    thread pete(Worker("Pete"));
    thread alice(Worker("Alice"));

    bob.join();
    sara.join();
    tom.join();
    pete.join();
    alice.join();

    cout << "Boss says: Great work. Now you can go home" << endl;

    return 0;
}