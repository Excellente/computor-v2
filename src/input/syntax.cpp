#include "input/syntax.hpp"

SyntaxAnalyzer::~SyntaxAnalyzer(){}

SyntaxAnalyzer::SyntaxAnalyzer()
{
}

bool SyntaxAnalyzer::isAtomic(string &t)
{
    int i;
    bool res = false;

    if (isname(t) || isnumber(t))
        return (!res);
    return (res);
}

void SyntaxAnalyzer::paranScan(char *l)
{
}

void SyntaxAnalyzer::parse(char *l)
{
    if (!strcmp(l, "quit") || !strcmp(l, "exit"))
        exit(EXIT_SUCCESS);
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