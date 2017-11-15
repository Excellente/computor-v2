#include "common.hpp"

bool isdigit(char c)
{
    regex rd("[0-9]");

    if (regex_match(string(1, c), rd))
        return (true);
    return (false);
}