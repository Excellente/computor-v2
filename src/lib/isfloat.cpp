#include "common.hpp"

bool isfloat(string s)
{
    regex rf("[0-9]+\\.[0-9]+");
    return (regex_match(s, rf));
}