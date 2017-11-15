#include "input/syntax.hpp"

SyntaxAnalyzer::SyntaxAnalyzer(){}
SyntaxAnalyzer::~SyntaxAnalyzer(){}

bool SyntaxAnalyzer::isAtomic(string &t)
{
    int i;
    bool res = false;

    if (isname(t) || isnumber(t))
        return (!res);
    return (res);
}

void SyntaxAnalyzer::parse(char *l)
{
}