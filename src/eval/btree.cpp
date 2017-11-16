#include "eval/btree.hpp"

BTree::~BTree(){}

BTree::BTree(string op) : _op(op)
{
    _value = 0;
    _left = NULL;
    _right = NULL;
}

vector<string> BTree::getOperand1() const{
    return (_oprnd1);
}

vector<string> BTree::getOperand2() const{
    return (_oprnd2);
}

void BTree::set_operands(Maps _tkns)
{
    int i = 0;
    mapit_t _end = _tkns.end();
    mapit_t _bgn = _tkns.begin();

    for (; *_bgn != _op; _bgn++)
    {
        _oprnd1.push_back(_tkns.value_at(*_bgn));
    }
    if (*_bgn == _op)
        _bgn++;
    for (; _bgn != _end; _bgn++)
        _oprnd2.push_back(_tkns.value_at(*_bgn));
}