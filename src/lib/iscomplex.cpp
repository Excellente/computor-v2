#include "common.hpp"

bool iscomplex(string s)
{
    regex rc("([0-9]+)?i");
    return (regex_match(s, rc));
}