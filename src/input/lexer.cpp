#include "input/lexer.hpp"

Lexer::~Lexer(){}

Lexer::Lexer()
{
    _index = 0;
    _end = _tkns.end();
    _bgn = _tkns.begin();
}

string Lexer::look_ahead()
{
    int i = _index;
    _end = _tkns.end();
    _bgn = _tkns.begin();

    while (i--) _bgn++;
    if ((_bgn + 1) == _end) return (_EOF_);
    return (_tkns.value_at(_index + 1));
}

Maps Lexer::getTokens() const{
    return (_tkns);
}

void Lexer::delete_map(){
    _tkns.delete_m();
}

string Lexer::getNextToken()
{
    int i = _index;
    _end = _tkns.end();
    _bgn = _tkns.begin();

    while (i--) _bgn++;
    if (_bgn == _end) return (_EOF_);
    string ret = _tkns.value_at(_index);
    _index++;
    return (ret);
}

void Lexer::printmap()
{
    int len = _tkns.length();
    mapit_t ecit = _tkns.end();
    mapit_t bcit = _tkns.begin();
    for (int i = 0; i < len; i++, bcit++)
        cout << *bcit << " -> " << _tkns[i] << endl;
}

void Lexer::tokenize(char *s)
{
    int i = 0;
    do
    {
        while (iswhitespace(s[i])) i++;
        if (isdigit(s[i]))
        {
            int end;
            int start = i;

            while (isdigit(s[i])) i++;
            end = i;
            _tkns["NUMBER"] = _substr(s, start, end);
        }
        if (isalpha(s[i]))
        {
            int end;
            int start = i;

            while (isalpha(s[i])) i++;
            end = i;
            _tkns["NAME"] = tolower(_substr(s, start, end));
            i--;
        }
        if (s[i] == TOK_CO)
            _tkns["COMMA"] = s[i];
        if (s[i] == TOK_LP)
            _tkns["L_PAREN"] = s[i];
        if (s[i] == TOK_RP)
            _tkns["R_PAREN"] = s[i];
        if (s[i] == TOK_QM)
            _tkns["Q_MARK"] = s[i];
        if (s[i] == TOK_LSB)
            _tkns["L_BRAC"] = s[i];
        if (s[i] == TOK_RSB)
            _tkns["R_BRAC"] = s[i];
        if (s[i] == TOK_SC)
            _tkns["SEMICO"] = s[i];
        if (s[i] == TOK_DP)
            _tkns["D_POIN"] = s[i];
        if (s[i] == TOK_OADD)
            _tkns[OP_ADD] = s[i];
        if (s[i] == TOK_OSUB)
            _tkns[OP_SUB] = s[i];
        if (s[i] == TOK_ODIV)
            _tkns[OP_DIV] = s[i];
        if (s[i] == TOK_OMUL)
            _tkns[OP_MUL] = s[i];
        if (s[i] == TOK_OMOD)
            _tkns[OP_MOD] = s[i];
        if (s[i] == TOK_OEXP)
            _tkns[OP_EXP] = s[i];
        if (s[i] == TOK_OEQU)
            _tkns[OP_EQU] = s[i];
        i++;
    }
    while (s[i] != '\0');
}