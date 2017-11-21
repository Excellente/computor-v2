#include "common.hpp"

bool isnumber(string s)
{
    regex rn("[0-9]+\\.[0-9]+|[0-9]+");
    return (regex_match(s, rn));
}