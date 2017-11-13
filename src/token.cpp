#include <string>
#include <vector>
#include <iostream>

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
    while (i <= e && l[i] != '\0')
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

int main(void)
{
    string s = _substr("ZaMani", 0, 100);

    cout << s << endl;
    cout << tolower(s) << endl;
    return (0);
}