#include <string>
#include <vector>
#include <iostream>

using namespace std;

template <class T>
void print(vector<T> &v)
{
    typename vector<T>::iterator evi = v.end();
    typename vector<T>::iterator bvi = v.begin();
    for (; bvi != evi; bvi++)
        cout << *bvi << " ";
    cout << endl;
}

static vector<string> tokenize(string del, string _exp)
{
    int len;
    size_t pos;
    vector<int> delpos;
    vector<string> terms;

    // while (p[last] != '+' && p[last] != '-' && p[last] != '\0')
    // last++;
    // t = p.substr(first, last - first);
    // if (p[last] != '\0')
    //     last++;
    // first = last;
    // if (!regex_match(t, rg))
    // {
    //     cout << t << endl;
    //     cerr << "Error: InvalidTermFormat\n";
    //     exit(EXIT_FAILURE);
    // }

    len = 0;
    for (int i = 0; _exp[i] != '\0'; i++)
    {
        if (_exp[i] != '*' || _exp[i] != '-' || _exp[i] != '^' || _exp[i] != '(' ||
            _exp[i] != '/' || _exp[i] != '+' || _exp[i] != '%' || _exp[i] != ')')
            delpos.push_back(i);
        len++;
    }
    print(delpos);
    terms.push_back(_exp.substr(0, delpos[0]));
    // for (int i = 1; i < len; i++)
    //     terms.push_back(_exp.substr(delpos[i - 1] + 1, (delpos[i] - delpos[i - 1]) - 1));
    return (terms);
}

int main(void)
{
    string s = string("x + z - 3");
    vector<string> v = tokenize("=", s);

    vector<string>::iterator bi = v.begin();
    vector<string>::iterator ei = v.begin();
    for (; bi != ei; bi++)
        cout << *bi << " ";
    cout << endl;
    return (0);
}