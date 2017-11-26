#include "common.hpp"

bool isfunction(string s)
{
    regex rf("[a-zA-Z]+\\([a-zA-Z]\\)|[a-zA-Z]+\\([0-9]+\\)");
    return (regex_match(s, rf));
}