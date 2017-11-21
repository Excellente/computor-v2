#include "eval/btree.hpp"

BTree::~BTree(){}
BTree::BTree()
{
    _value = 0;
    _name = "";
    _left = NULL;
    _right = NULL;
}

BTree::BTree(string op) : _name(op)
{
    _value = 0;
    _left = NULL;
    _right = NULL;
}

void BTree::setValue(float _v){
    _value = _v;
}

int BTree::getValue() const{
    return (_value);
}

string BTree::getName() const{
    return (_name);
}

BTree *BTree::getLeft() const{
    return (_left);
}

BTree *BTree::getRight() const{
    return (_right);
}

Maps BTree::getOperand1() const{
    return (_oprnd1);
}

Maps BTree::getOperand2() const{
    return (_oprnd2);
}

void BTree::visit(){
    cout << _name << endl;
}

int BTree::operator+(BTree const &r){
    return (_value + r.getValue());
}

int BTree::operator-(BTree const &r){
    return (_value - r.getValue());
}

int BTree::operator*(BTree const &r){
    return (_value * r.getValue());
}

int BTree::operator/(BTree const &r){
    return (_value / r.getValue());
}

BTree &BTree::operator=(BTree const &r)
{
    _name = r._name;
    _left = r._left;
    _value = r._value;
    _right = r._right;
    _oprnd1 = r._oprnd1;
    _oprnd2 = r._oprnd2;
    return (*this);
}

void BTree::print()
{
    if (_left != NULL)
        _left->print();
    visit();
    if (_right != NULL)
        _right->print();
}

void BTree::set_operands(Maps _tkns)
{
    int i = 0;
    int j = 0;
    mapit_t _end = _tkns.end();
    mapit_t _bgn = _tkns.begin();

    i = j = _tkns.index_of(_name);
    _oprnd1 = _tkns._submap(0, --i);
    _oprnd2 = _tkns._submap(++j);
}