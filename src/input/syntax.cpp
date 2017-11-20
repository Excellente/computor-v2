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
        return (true);
    return (false);
}

// void SyntaxAnalyzer::parse(Lexer _le, BTree *bt)
// {
//     string _tkn = _le.getNextToken();
//     if (isname(_tkn) && le.look_ahead() == "=")
//         cout << "possible var_declaration" << endl;
//     else
//         cout << "not yet handled" << endl;
// }

void SyntaxAnalyzer::parse(Maps _tk, BTree *bt)
{
    // string la("");
    // string tmp_tkn("");
    // while (1)
    // {
    //     for (i = 0; ops[i] != _NULL_ && !(found = _tkns.search(ops[i])); i++);
    //     if (found)
    //     {
    //         bt = new BTree(ops[i]);
    //         bt->set_operands(_tkns);
    //     }
    // }
    // // while[ tree is not atomic]
    //  -> node_eval[unamtomic node];
    //  -> go further down the tree;
    // int i;
    // bool found;
    string ops[] = {OP_EQU, OP_ADD, OP_SUB, OP_DIV, OP_MUL, OP_MOD, OP_EXP, _NULL_};
    // for (i = 0; ops[i] != _NULL_ && !(found = _tkns.search(ops[i])); i++);    
    // this->_tkns = _tk;
    // if (found)
    // {
        bt = new BTree(ops[0]);
        // bt->set_operands(_tkns);
        // cout << bt->getOp() << endl;
        // bt->getOperand1().print();
        // cout << endl;
        // bt->getOperand2().print();
        // cout << endl << endl;
        // parse(bt->getOperand1(), bt->getLeft());
        // parse(bt->getOperand2(), bt->getRight());
        // node_eval(left_operand: Maps, parent: BTree):
        //      -> if isAtomic(left_operand)
        //          parent->left = new Btree(left_operand[0]);
        //      -> else
        //          parse(left_operand, left);
        // node_eval(right_operand):
    // }
    // else
    // {
    //     bt = new BTree(_tk[0]);
    // }
    // bt->print();
    // cout << endl;
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