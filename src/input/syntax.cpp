#include "input/syntax.hpp"

SyntaxAnalyzer::~SyntaxAnalyzer(){}
SyntaxAnalyzer::SyntaxAnalyzer()
{
    _tkn_num = 0;
    _end = _tkns.end();
    _bgn = _tkns.begin();
}

string SyntaxAnalyzer::look_ahead()
{
    return (_tkns.value_at(*_bgn));
}

string SyntaxAnalyzer::getNextToken()
{
    string st;
    if (_bgn != _end)
    {
        st = _tkns.value_at(*_bgn);
        _bgn++;
        _tkn_num++;
    }
    else
        return (_EOF_);
    return (st);
}

void SyntaxAnalyzer::parse(Maps _tkns)
{
    string la("");
    string tmp_tkn("");

    this->_tkns = _tkns;
    while (tmp_tkn != _EOF_)
    {
        tmp_tkn = getNextToken();
        if (tmp_tkn.compare("=") && _tkn_num == 1)
        {
            cerr << "ERROR" << endl;
            exit(EXIT_FAILURE);
        }
        if (isname(tmp_tkn))
        {
            la = look_ahead();
            if (la == (string(1, TOK_LP)))
                ;// _function();
        }
        // to do:
        // -> template classes: for ast implimentation
        // -> build ast class;
    }
}