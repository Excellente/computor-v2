#include "common.hpp"

void print(vector<string> s)
{
    vector<string>::iterator start = s.begin();
    vector<string>::iterator end = s.end();

    while (start != end)
    {
        cout << *start << " ";
        start++;
    }
    cout << endl;
}