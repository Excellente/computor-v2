#include "input/syntax.hpp"

int main(int argc, char *argv[])
{
    char *line;
    SyntaxAnalyzer sa;

    while (1)
    {
        cout << "$> ";
        line = sa.read_line();
        sa.parse(line);
    }
    return (0);
}