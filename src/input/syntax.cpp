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

void SyntaxAnalyzer::parse(Maps _tk, BTree *&bt)
{
    int i;
    bool found;
    string ops[] = {OP_EQU, OP_ADD, OP_SUB, OP_DIV, OP_MUL, OP_MOD, OP_EXP, _NULL_};

    this->_tkns = _tk;
    for (i = 0; ops[i] != _NULL_ && !(found = _tkns.search(ops[i])); i++);
    if (found)
    {
        bt = new BTree(ops[i]);
        bt->set_operands(_tkns);
        parse(bt->getOperand1(), bt->_left);
        parse(bt->getOperand2(), bt->_right);
        // node_eval(left_operand: Maps, parent: BTree):
        //      -> if isAtomic(left_operand)
        //          parent->left = new Btree(left_operand[0]);
        //      -> else
        //          parse(left_operand, left);
        // node_eval(right_operand): // done
    }
    else
    {
        bt = new BTree(_tk[0]);
    }
}