#include "eval/function.hpp"

Function::~Function(){}

Function::Function(BTree *&r)
{
    _val = 0;
    _f_rhs = new BTree(*r);
}

BTree *Function::getFrhs() const{
    return (_f_rhs);
}