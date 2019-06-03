#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

int main()
{
    vector<function<string(string)>> functions
            {
                    [](string instr) { return "<strong>" + instr + "</strong>"; },
                    [](string instr) { return "<h3>" + instr + "</h3>"; },
                    [](string instr) { return "<p>" + instr + "</p>"; },
                    [](string instr) { return "<div>" + instr + "</div>"; },
            };

    string input = "Tag me";

    for (auto func : functions)
    {
        input = func(input);
    }

    cout << input << endl;
    return 0;
}