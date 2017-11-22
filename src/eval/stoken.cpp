#include "eval/stoken.hpp"

SToken::~SToken(){}

SToken::SToken(bool isop, string value)
{
    this->_isOp = isop;
    this->_value = value;
}

string SToken::getValue() const{
    return (_value);
}

SToken &SToken::operator=(const SToken &r)
{
    this->_isOp = r._isOp;
    this->_value = r._value;
    return (*this);
}