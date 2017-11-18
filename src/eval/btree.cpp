#include "eval/btree.hpp"

BTree::~BTree(){}

BTree::BTree(string op) : _op(op)
{
    _value = 0;
    _left = NULL;
    _right = NULL;
}

Maps BTree::getOperand1() const{
    return (_oprnd1);
}

Maps BTree::getOperand2() const{
    return (_oprnd2);
}

void BTree::set_operands(Maps _tkns)
{
    int i = 0;
    int j = 0;
    mapit_t _end = _tkns.end();
    mapit_t _bgn = _tkns.begin();

    i = j = _tkns.index_of(_op);
    _oprnd1 = _tkns._submap(0, --i);
    _oprnd2 = _tkns._submap(++j);
}