#include <map>
#include <string>
#include <vector>
#include <iostream>
// #include "input/map.hpp"
#include <exception>

using namespace std;

string _substr(string l, int s, int e)
{
    int i;
    int j = 0;
    char *str;

    if ((e < s))
        return ("");
    str = (char *)malloc((sizeof(char) * (e - s)) + 1);
    if (str == NULL)
        return ("");
    for (i = 0; i != s && l[i] != '\0'; i++);
    while (i < e && l[i] != '\0')
        str[j++] = l[i++];
    str[j] = '\0';
    string ret(str);
    return (ret);
}

string tolower(string s)
{
    string tl(s);
    for (int i = 0; tl[i] != '\0'; i++)
        if (tl[i] >= 65 && tl[i] <= 90)
            tl[i] += 32;
    return (tl);
}

bool isalpha(char c)
{
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return (true);
    return (false);
}

class ErrorException : public exception {
    using exception::what;
    public:
        virtual const char* what() throw() {
            return "ErrorExcpetion";
        }
};

int divide(int a, int b) throw(ErrorException)
{
    int q;
    ErrorException ee;

    if (b == 0)
        throw ee;
    q = a / b;
    return (q);
}

void _math()
{
    divide(1, 0);
}

int main(void)
{
    try
    {
        string st("c");
        vector<string> v;
        for (int i = 0; i < 4; i++)
            v.push_back(st.append(1, 65 + i));
        vector<string> t = v;
        vector<string>::iterator it = v.begin();
        vector<string>::iterator tt = t.begin();
        if ((*it).compare("cA") == 0)
            cout << "*it -> cA" << endl;
        else
            cout << *(++it) << endl;
        st.compare("") == 0 ? divide(1, 8) : 0;
    }
    catch(ErrorException &e){
        cerr << e.what() << endl;
    }
    return (0);
}