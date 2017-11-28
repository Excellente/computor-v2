#include "common.hpp"

bool isop(string s)
{
    regex ro("OP_ADD|OP_SUB|OP_DIV|OP_MUL|OP_MOD|OP_EXP|OP_EQU|\\+|-|/|\\*|\\^|\\%|=");
    if (regex_match(s, ro) || s == "**")
        return (true);
    return (false);
}