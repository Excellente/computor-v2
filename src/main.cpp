#include "eval/btree.hpp"
#include "input/lexer.hpp"
#include "input/syntax.hpp"
#include "input/iostream.hpp"

int main(int argc, char *argv[])
{
    Lexer le;
    char *line;
    IOStream ios;
    SyntaxAnalyzer sa;
    BTree *root;

    cout << "\nComputor-v2 (c) November 2017, [rap]dean\n free software, dean-techonlogies inc.\n" << endl;
    while (1)
    {
        try{
            cout << "$> ";
            line = ios.read_line();
            if (!strcmp(line, "quit") || !strcmp(line, "exit"))
                exit(EXIT_SUCCESS);
            le.tokenize(line);
            sa.parse(le.getTokens(), root);
            // le.printmap();
            // cout << line << endl;
        }
        catch(IndexOutOfBounds &e){
            cerr << e.what() << endl;
            exit(EXIT_FAILURE);
        }
        catch(...){
            cerr << "Error: UnknownException" << endl;
            exit(EXIT_FAILURE);
        }

    }
    return (0);
}