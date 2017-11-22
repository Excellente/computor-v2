#include "common.hpp"
#include "eval/stoken.hpp"

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

void print_stack(stack<SToken> st)
{
    vector<SToken> tmp;
    vector<SToken>::iterator bg;
    vector<SToken>::iterator en;

    while (!st.empty())
    {
        tmp.push_back(st.top());
        st.pop();
    }
    en = tmp.end();
    bg = tmp.begin();
    for (; bg != en; bg++)
        cout << bg->getValue() << " ";
    bg = tmp.begin();
    for (; bg != en; bg++)
        st.push(*bg);
    cout << endl;
}