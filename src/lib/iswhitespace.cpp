#include "common.hpp"

bool iswhitespace(char c)
{
    if ((c >= 9 && c <= 13) || c == 32 || c == '\t')
        return (true);
    return (false);
}