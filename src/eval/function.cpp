#include "eval/function.hpp"

Function::~Function(){}

Function::Function(BTree *r)
{
    tostack(r);
}

void tostack(BTree *r)
{
    // initialize stoken with tree node and send to stack
    //
    SToken st;
}