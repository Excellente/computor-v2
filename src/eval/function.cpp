#include "eval/function.hpp"

Function::~Function(){}

Function::Function(BTree *&r)
{
    _str = "";
    _f_rhs = new BTree(*r);
}

BTree *Function::getFrhs() const{
    return (_f_rhs);
}

string Function::getString() const{
    return (_str);
}

void Function::tostring(BTree *r)
{
    if (r->_left != NULL)
        tostring(r->_left);
    _str += r->getName() + " ";
    if (r->_right != NULL)
        tostring(r->_right);
}