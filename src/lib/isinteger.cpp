#include "common.hpp"

bool isinteger(string s)
{
    regex ri("[0-9]+");
    return (regex_match(s, ri));
}