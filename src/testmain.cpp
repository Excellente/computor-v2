#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <regex>
#include <stdio.h>
#include <exception>
#include "input/map.hpp"
#include "common.hpp"

using namespace std;

bool isfunction(string s)
{
    regex rf("[a-zA-Z]+\\([a-zA-Z]\\)");
    return (regex_match(s, rf));
}

bool isnumber(string s)
{
    regex rn("[0-9]+\\.[0-9]+|[0-9]+");
    return (regex_match(s, rn));
}

bool isop(string s)
{
    regex ro("OP_ADD|OP_SUB|OP_DIV|OP_MUL|OP_MOD|OP_EXP|OP_EQU|\\+|-|/|\\*|\\^|\\%|=");
    if (regex_match(s, ro) || s == "**")
        return (true);
    return (false);
}

bool isvalid_char(char s)
{
    if (isop(string(1, s)) || iswhitespace(s) || isdigit(s) || isalpha(s) ||
        s == TOK_CO || s == TOK_LP || s == TOK_RP || s == TOK_QM ||
        s == TOK_LSB || s == TOK_RSB || s == TOK_SC || s == TOK_DP)
        return (true);
    return (false);
}

bool isdigit(char c)
{
    regex rd("[0-9]");

    if (regex_match(string(1, c), rd))
        return (true);
    return (false);
}

int main(int ac, char *av[])
{
    double num = 2.3;
    string test = "2f";
    // string buf = stod(test);
    char name[50]; //[[2,3];[3,4,5,6];[43,3,34]]

    sprintf(name, "%f", num);
    cout <<  isdigit('2') << endl;

    return (0);
}