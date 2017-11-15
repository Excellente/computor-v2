#include "common.hpp"

bool isnumber(string &s)
{
    regex rn("[0-9]+");

    if (regex_match(s, rn))
        return (true);
    return (false);
}