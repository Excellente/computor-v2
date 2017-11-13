#include "input/lexer.hpp"

Lexer::~Lexer(){}
Lexer::Lexer(){}

bool Lexer::isdigit(char c)
{
    if (c >= 48 && c <= 57)
        return (true);
    return (false);
}

bool Lexer::isalpha(char c)
{
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return (true);
    return (false);
}

bool Lexer::iswhitespace(char c)
{
    if ((c >= 9 && c <= 13) || c == 32)
        return (true);
    return (false);
}

string Lexer::tolower(string s)
{
    string tl(s);
    for (int i = 0; tl[i] != '\0'; i++)
        if (tl[i] >= 65 && tl[i] <= 90)
            tl[i] += 32;
    return (tl);
}

void Lexer::printmap()
{
    int len = _tkns.length();
    vector<string>::iterator ecit = _tkns.end();
    vector<string>::iterator bcit = _tkns.begin();
    for (int i = 0; i < len; i++, bcit++)
        cout << *bcit << " -> " << _tkns[i] << endl;
}

string _substr(string l, int s, int e)
{
    int i;
    int j = 0;
    char *str;

    if ((e < s))
        return ("");
    str = (char *)malloc((sizeof(char) * (e - s)) + 1);
    if (str == NULL)
        return ("");
    for (i = 0; i != s; i++);
    while (i < e && l[i] != '\0')
        str[j++] = l[i++];
    str[j] = '\0';
    string ret(str);
    return (ret);
}

void Lexer::tokenize(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
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
        }
        if (s[i] == TOK_LP)
            _tkns["L_PARENTH"] = s[i];
        if (s[i] == TOK_RP)
            _tkns["R_PARENTH"] = s[i];
        if (s[i] == TOK_EQ)
            _tkns["EQUAL"] = s[i];
        if (s[i] == TOK_LSB)
            _tkns["L_S_BRACKET"] = s[i];
        if (s[i] == TOK_RSB)
            _tkns["R_S_BRACKET"] = s[i];
        if (s[i] == TOK_CO)
            _tkns["COMMA"] = s[i];
        if (s[i] == TOK_SC)
            _tkns["SEMICOLON"] = s[i];
        if (s[i] == TOK_OA)
            _tkns["OP_ADD"] = s[i];
        if (s[i] == TOK_OS)
            _tkns["OP_SUBTRACT"] = s[i];
        if (s[i] == TOK_OD)
            _tkns["OP_DIVIDE"] = s[i];
        if (s[i] == TOK_OM)
            _tkns["OP_MULTIPLY"] = s[i];
        if (s[i] == TOK_DP)
            _tkns["DECIMAL_POINT"] = s[i];
    }
}