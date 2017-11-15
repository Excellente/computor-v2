#include "common.hpp"

bool isalpha(char c)
{
    regex ra("[a-zA-Z]");

    if (regex_match(string(1, c), ra))
        return (true);
    return (false);
}