#include "input/syntax.hpp"

SyntaxAnalyzer::~SyntaxAnalyzer(){}

SyntaxAnalyzer::SyntaxAnalyzer()
{
    _bracket = 0;    
    _isFloat = false;
    _isUnknown = false;
    _isComplex = false;
    _isFunction = false;
}

string SyntaxAnalyzer::getLhs() const
{
    return (_lhs);
}

string SyntaxAnalyzer::getRhs() const
{
    return (_rhs);
}

void SyntaxAnalyzer::setLhs(string s)
{
    _lhs = s;
}

void SyntaxAnalyzer::setRhs(string s)
{
    _rhs = s;
}

bool SyntaxAnalyzer::isAtomic(string &s)
{
    int i;
    bool res = false;

    for(i = 0; (s[i] >= 48 && s[i] <= 57) && s[i] != '\0'; i++);
    if (s[i] == '\0')
        return (!res);
    return (res);
}

void SyntaxAnalyzer::paranScan(char *l)
{
    for (int i = 0; l[i] != '\0'; i++)
    {
        if (l[i] == TOK_LB)
            _bracket++;
        if (l[i] == TOK_RB)
            _bracket--;
    }
    if (_bracket != 0)
    {
        cerr << "syntax error: bracket mismatch" << endl;
        exit(EXIT_FAILURE);
    }
}

// bool isVarname()

bool SyntaxAnalyzer::parseExpression(char *l)
{
    regex rvar("[a-zA-Z]+(\\(([a-zA-Z]|[0-9])\\))?");
    
    _sp = strsplit("=", (string)l);
    setLhs(_sp[0]);
    setRhs(_sp[1]);
    trim(_lhs);
    trim(_rhs);
    if (!regex_match(_lhs, rvar))
        return (false);
    if (isAtomic(_rhs))
        return (true);
    else
    {
        paranScan(l);
    }
    return (1);
}

void SyntaxAnalyzer::parse(char *l)
{
    bool res = true;
    regex ra("[a-zA-Z]+|[0-9]+");

    if (!strcmp(l, "quit") || !strcmp(l, "exit"))
        exit(EXIT_SUCCESS);
    if (strchr(l, '=') != NULL)
        res &= parseExpression(l);
    else
    {
        if (regex_match(l, ra))
        {
            if (l[0] >= 48 && l[0] <= 57)
                cout << l << endl;
            else
                cout << "0" << endl;
        }
        else
            res &= 0;
    }
    if (!res)
        cout << "syntax error" << endl;
}

void SyntaxAnalyzer::ltrim(string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

void SyntaxAnalyzer::rtrim(string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

void SyntaxAnalyzer::trim(string &s) {
    ltrim(s);
    rtrim(s);
}

char *SyntaxAnalyzer::read_line(void)
{
    int c;
    int position = 0;
    int bufsize = BUFF_SIZE;
    char *buffer = (char *)malloc(sizeof(char) * bufsize);

    if (!buffer)
    {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        c = getchar();

        if (c == EOF || c == '\n')
        {
            buffer[position] = '\0';
            return (buffer);
        }
        else
        {
            buffer[position] = c;
        }
        position++;
        if (position >= bufsize)
        {
            bufsize += BUFF_SIZE;
            buffer = (char *)realloc(buffer, bufsize);
            if (!buffer)
            {
                fprintf(stderr, "lsh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}