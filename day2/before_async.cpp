#include <iostream>
#include <chrono>
#include <thread>
#include <string>

using namespace std;

string fetchDataFromDB(string recvData)
{
    this_thread::sleep_for(chrono::seconds(5));
    return "DB_" + recvData;
}

string fetchDataFromFile(string recvData)
{
    this_thread::sleep_for(chrono::seconds(5));
    return "File_" + recvData;
}

int main()
{
    auto start = chrono::system_clock::now();
    string dbData = fetchDataFromDB("Data");
    string fileData = fetchDataFromFile("Data");

    auto end = chrono::system_clock::now();
    auto diff = chrono::duration_cast<chrono::seconds>(end - start).count();
    cout << "Time taken: " << diff << " seconds" << endl;
    cout << dbData << " :: " << fileData << endl;
    return 0;
}