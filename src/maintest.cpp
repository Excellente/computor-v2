#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <regex>
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
    regex rn("[a-zA-Z]");

    if (regex_match(string(1, c), rn))
        return (true);
    return (false);
}

bool isnumber(string s)
{
    regex rn("[0-9]+");

    if (regex_match(s, rn))
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

int main(int ac, char *av[])
{
    try
    {
        cout << tolower(av[1]) << endl;
    }
    catch(ErrorException &e){
        cerr << e.what() << endl;
    }
    return (0);
}