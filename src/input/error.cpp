#include "input/error.hpp"

Error::Error(){}
Error::~Error(){}

bool Error::isleaf(string s)
{
    if (isnumber(s) || isname(s) || ismatrix(s) ||
        iscomplex(s) || isfunction(s) || s == "?")
        return (true);
    return (false);
}

bool Error::hasop(BTree *bt)
{
    bool op = false;

    if (bt->_left != NULL)
        op |= hasop(bt->_left);
    if (isop(bt->getName()))
        ;
        op = true;
    if (bt->_right != NULL)
        op |= hasop(bt->_right);
    return (op);
}

void Error::ScanTree(BTree *bt) throw (InvalidSyntaxException)
{
    InvalidSyntaxException ise;

    if (!hasop(bt))
        cout << "\033[1;31merror: \033[0mno operator found." << endl;
    OperatorScan(bt);
}

void Error::OperatorScan(BTree *bt) throw (InvalidSyntaxException)
{
    InvalidSyntaxException ise;

    if (bt->_left != NULL)
        OperatorScan(bt->_left);
    if (isop(bt->getName()) && (!bt->_left || !bt->_right))
        cout << "\033[1;31merror: \033[0mbinary operator: " << bt->getName() << " must two operands." << endl;
    if (!bt->_left && !isleaf(bt->getName()) && !bt->_right)
        cout << "\033[1;31merror: \033[0m: " << bt->getName() << " invalid operand." << endl;
    if (bt->_right != NULL)
        OperatorScan(bt->_right);
}

void Error::OperandScan(BTree *bt) throw (InvalidOperandException)
{
    InvalidOperandException ioe;

    if (bt->_left != NULL)
        OperandScan(bt->_left);
    if (bt->getName() == "=" && isnumber(bt->_left->getName()))
        cout << "\033[1;31merror: \033[0minvalid syntax: " << bt->_left->getName() << " must be a valid var_name." << endl;
    if (bt->_right != NULL)
        OperandScan(bt->_right);
}
