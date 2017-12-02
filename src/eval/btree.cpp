#include "eval/btree.hpp"

BTree::~BTree(){}
BTree::BTree()
{
    _value = 0;
    _name = "";
    _mat = NULL;
    _left = NULL;
    _right = NULL;
}

BTree::BTree(string op, int sign) : _name(op), _sign(sign)
{
    _value = 0;
    _mat = NULL;
    _left = NULL;
    _right = NULL;
}

BTree::BTree(const BTree &r)
{
    _mat = r._mat;
    _sign = r._sign;
    _name = r._name;
    _value = r._value;
    _oprnd1 = r._oprnd1;
    _oprnd2 = r._oprnd2;
    if (r._left != NULL)
        _left = new BTree(*r._left);
    else
        _left = r._left;
    if (r._right != NULL)
        _right = new BTree(*r._right);
    else
        _right = r._right;
}

int BTree::pow(int b, int e)
{
    int res = 1;

    for (int i = 0; i < e; i++)
        res *= b;
    return (res);
}

int BTree::getSign() const{
    return (_sign);
}

int BTree::getValue() const{
    return (_value);
}

string BTree::getName() const{
    return (_name);
}

Matrix *BTree::getMat() const{
    return (_mat);
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
    _mat = r._mat;
    _sign = r._sign;
    _name = r._name;
    _left = r._left;
    _value = r._value;
    _right = r._right;
    _oprnd1 = r._oprnd1;
    _oprnd2 = r._oprnd2;
    return (*this);
}

void BTree::tostring(string s)
{
    if (_left != NULL)
        tostring(s);
    cout << _name << s;
    if (_right != NULL)
        tostring(s);
}

void BTree::setMat(Matrix *_m){
    _mat = _m;
}

void BTree::setName(string _n){
    _name = _n;
}

void BTree::setValue(float _v){
    _value = _v;
}

void BTree::visit(){
    if (_sign == -1)
        cout << "- ";
    cout << _name << endl;
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