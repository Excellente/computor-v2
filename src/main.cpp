#include "eval/btree.hpp"
#include "input/lexer.hpp"
#include "input/syntax.hpp"
#include "eval/shunting.hpp"
#include "input/iostream.hpp"

int main(int argc, char *argv[])
{
    char *line;
    IOStream ios;
    Shunting sy;
    stack<SToken> tmp;
    BTree *root = NULL;
    Lexer le = Lexer();
    SyntaxAnalyzer sa = SyntaxAnalyzer();

    cout << "Computor-v2 1.0\n  Free Software(c) November 2017, [rap]dean\n   mathware, dean-techonlogies inc.\n" << endl;
    while (1)
    {
        try{
            cout << "$> ";
            line = ios.read_line();
            if (!strcmp(line, "quit") || !strcmp(line, "exit"))
                exit(EXIT_SUCCESS);
            le.tokenize(line);
            tmp = sy.shuntingYard(le.getTokens());
            sa.build_ast(tmp, root);
            sa.parse(root);
            // root->tostring(" ");
            root->print();
            // sa.build_ast(le.getTokens(), root);
            le.delete_map();
            sa.delete_tree(root);
        }
        catch(IndexOutOfBounds &e){
            cerr << e.what() << endl;
            exit(EXIT_FAILURE);
        }
        catch(InvalidSyntaxException &e){
            cerr << e.what() << endl;
            exit(EXIT_FAILURE);
        }
    }
    return (0);
}