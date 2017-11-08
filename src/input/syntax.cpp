#include "input/syntax.hpp"

SyntaxAnalyzer::~SyntaxAnalyzer(){}

SyntaxAnalyzer::SyntaxAnalyzer()
{
    isFloat = false;
    isUnknown = false;
    isComplex = false;
    isFunction = false;
}

void SyntaxAnalyzer::parse(char *l)
{
    regex ra("[a-zA-Z]+(\\s)=(\\s)");

    /* regex to check for all possible inputs
    ** quit on error. assignment input check */
    if (regex_match(l, ra))
        cout << "match" << endl;
    else
        cout << "ERROR! unexpected input" << endl;
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