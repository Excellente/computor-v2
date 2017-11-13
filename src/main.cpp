#include "input/lexer.hpp"
#include "input/syntax.hpp"

void printmap(map<string, string> m)
{
    map<string, string>::const_iterator ecit = m.end();
    map<string, string>::const_iterator bcit = m.begin();
    for (; bcit != ecit; bcit++)
        cout << bcit->first << " ";
    cout << endl;
}

int main(int argc, char *argv[])
{
    char *line;
    Lexer le;
    SyntaxAnalyzer sa;

    cout << "\nComputor-v2 (c) November 2017, [rap]dean\n free software, dean-techonlogies inc.\n" << endl;
    while (1)
    {
        cout << "$> ";
        line = sa.read_line();
        le.tokenize(line);
        le.printmap();
        // sa.parse(line);
        // cout << line << endl;
    }
    return (0);
}