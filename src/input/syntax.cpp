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

bool SyntaxAnalyzer::isAtomic(Maps m)
{
    if (m.length() == 1 && (isnumber(m[0]) || isname(m[0])))
        cout << "yep is atomic" << endl;
    else
        cout << "nope needs eval" << endl;
    return (true);
}

void SyntaxAnalyzer::parse(Maps _tk, BTree *bt)
{
    // string la("");
    // string tmp_tkn("");
    int i;
    bool found;
    string ops[] = {OP_EQU, OP_ADD, OP_SUB, OP_DIV, OP_MUL, OP_MOD, OP_EXP, _NULL_};

    this->_tkns = _tk;
    for (i = 0; !(found = _tkns.search(ops[i])); i++);
    if (found)
    {
        bt = new BTree(ops[i]);
        bt->set_operands(_tkns);
        bt->getOperand1().print();
        cout << endl;
        bt->getOperand2().print();
        cout << endl << endl;        
        // node_eval(left_operand: Maps, parent: BTree):
        //      -> if isAtomic(left_operand)
        //          parent->left = new Btree(left_operand[0]);
        //      -> else
        //          parse(left_operand, left);
        // node_eval(right_operand):
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
    // }
}