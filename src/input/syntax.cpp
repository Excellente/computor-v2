#include "input/syntax.hpp"

SyntaxAnalyzer::~SyntaxAnalyzer(){}

SyntaxAnalyzer::SyntaxAnalyzer()
{
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

void SyntaxAnalyzer::parse(char *l)
{
    regex ra("[a-zA-Z]+|[0-9]+");
    regex ri(".(\\s+)=(\\s+).");

    if (strchr(l, '=') != NULL)
    {
        _sp = strsplit("=", (string)l);
        setLhs(_sp[0]);
        setRhs(_sp[1]);
    }
    else
    {
        // quit on error. assignment input check
        if (regex_match(l, ra))
        {
            if (l[0] >= 48 && l[0] <= 57)
                cout << l << endl;
            else
                cout << "0" << endl;
        }
        else
            cerr << "syntax error" << endl;
    }
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