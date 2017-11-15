#include "input/syntax.hpp"

SyntaxAnalyzer::~SyntaxAnalyzer(){}
SyntaxAnalyzer::SyntaxAnalyzer()
{
    _end = _tkns.end();
    _bgn = _tkns.begin();
}

string SyntaxAnalyzer::getNextToken()
{
    string st;
    if (_bgn != _end)
    {
        st = _tkns.value_at(*_bgn);
        _bgn++;
    }
    else
        return (_EOF_);
    return (st);
}

void SyntaxAnalyzer::parse(Maps _tkns)
{
    this->_tkns = _tkns;
}