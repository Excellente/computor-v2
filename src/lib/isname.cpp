#include "common.hpp"

bool isname(string s)
{
    regex rn("[a-zA-Z]+");

    if (regex_match(s, rn))
        return (true);
    return (false);
}