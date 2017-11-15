#include "common.hpp"

bool isname(string &s)
{
    int i;

    for (i = 0; isalpha(s[i]) && s[i] != '\0'; i++);
    if (s[i] == '\0')
        return (true);
    return (false);
}