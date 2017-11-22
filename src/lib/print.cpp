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
    while (!st.empty())
    {
        cout << st.top().getValue() << " ";
        st.pop();
    }
    cout << endl;
}