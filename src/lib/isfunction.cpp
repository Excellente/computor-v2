#include "common.hpp"

bool isfunction(string s)
{
    regex rf("[a-zA-Z]+\\([a-zA-Z]\\)");
    return (regex_match(s, rf));
}