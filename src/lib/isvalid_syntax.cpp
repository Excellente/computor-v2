#include "common.hpp"

bool isvalid_syntax(string s)
{
    if (isop(s) || ismatrix(s) || isfunction(s) ||
        isname(s) || isnumber(s) || iscomplex(s) ||
        s[0] == TOK_LP || s[0] == TOK_RP || s[0] == TOK_QM)
        return (true);
    return (false);
}