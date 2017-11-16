#include "input/syntax.hpp"

SyntaxAnalyzer::~SyntaxAnalyzer(){}
SyntaxAnalyzer::SyntaxAnalyzer()
{
    _tkn_num = 0;
    _end = _tkns.end();
    _bgn = _tkns.begin();
}

string SyntaxAnalyzer::look_ahead()
{
    return (_tkns.value_at(*_bgn));
}

string SyntaxAnalyzer::getNextToken()
{
    string st;
    if (_bgn != _end)
    {
        st = _tkns.value_at(*_bgn);
        _bgn++;
        _tkn_num++;
    }
    else
        return (_EOF_);
    return (st);
}

void SyntaxAnalyzer::parse(Maps _tk, BTree *bt)
{
    // string la("");
    // string tmp_tkn("");
    string ops[] = {OP_EQU, OP_ADD, OP_SUB, OP_DIV, OP_MUL, OP_MOD, OP_EXP, _NULL_};

    this->_tkns = _tk;
    if (_tkns.search(ops[0]))
    {
        bt = new BTree(ops[0]);
        bt->set_operands(_tkns);
        print(bt->getOperand1());
        print(bt->getOperand2());       // wrong results since more values have key -> NAME
                                        // find index_of() and use index to get value_at(locations);
        // node_eval();
        // cout << OP_EQU << ": found" << endl;
    }
    else
        cout << OP_EQU << ": not found" << endl;
    // while (ops[i] != _NUL_)
    // {
        // -> search for operator in token stream
        // -> if found:
        //              * construct an operator node
        //              * set operator operands
        //              * if (operand is not atomic)
        //              * parse(operand)
        // -> else:
        //          * search next operator
        // tmp_tkn = getNextToken();
        // if (tmp_tkn.compare("=") && _tkn_num == 1)
        // {
        //     cerr << "ERROR" << endl;
        //     exit(EXIT_FAILURE);
        // }
        // if (isname(tmp_tkn))
        // {
        //     la = look_ahead();
        //     if (la == (string(1, TOK_LP)))
        //         ;// _function();
        // }
        // to do:
        // -> template classes: for ast implimentation
        // -> build ast class;
    // }
}