#include "input/lexer.hpp"
#include "input/syntax.hpp"
#include "input/iostream.hpp"

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
    Lexer le;
    char *line;
    IOStream ios;
    SyntaxAnalyzer sa;

    cout << "\nComputor-v2 (c) November 2017, [rap]dean\n free software, dean-techonlogies inc.\n" << endl;
    while (1)
    {
        try{
            cout << "$> ";
            line = ios.read_line();
            if (!strcmp(line, "quit") || !strcmp(line, "exit"))
                exit(EXIT_SUCCESS);
            le.tokenize(line);
            le.printmap();
            // sa.parse(line);
            // cout << line << endl;
        }
        catch(IndexOutOfBounds &e){
            cerr << e.what() << endl;
        }
        catch(...){
            cerr << "Error: UnknownException" << endl;
        }

    }
    return (0);
}