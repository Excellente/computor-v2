#include "common.hpp"

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
    for (i = 0; i != s; i++);
    while (i < e && l[i] != '\0')
        str[j++] = l[i++];
    str[j] = '\0';
    string ret(str);
    return (ret);
}