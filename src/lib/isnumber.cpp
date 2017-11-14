#include "lib.hpp"

bool isnumber(string &s)
{
    int i;

    for (i = 0; isdigit(s[i]) && s[i] != '\0'; i++);
    if (s[i] == '\0')
        return (true);
    return (false);
}