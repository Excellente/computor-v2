#include <map>
#include <string>
#include <vector>
#include <iostream>
#include "input/map.hpp"

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

int main(void)
{
    Maps mps;
    string st("key");
    string si("value");
    map<string, string> _tkns;

    mps.insert(st, si);
    mps.print();
    // string s = "_tkns[(L_PARENTH + i )] = s[i]";
    // for (int i = 0; s[i] != '\0'; i++)
    // {
    //     if (isalpha(s[i]))
    //     {
    //         int end;
    //         int start = i;

    //         while (isalpha(s[i])) i++;
    //         end = i;
    //         cout << tolower(_substr(s, start, end)) << endl;
    //         // _tkns["NAME"] = tolower(_substr(s, start, end));
    //     }
    // }
    // string s = _substr("ZaMani", 0, 100);

    // cout << s << endl;
    // cout << tolower(s) << endl;
    return (0);
}