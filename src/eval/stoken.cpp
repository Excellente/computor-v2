#include "eval/stoken.hpp"

SToken::~SToken(){}

SToken::SToken(bool isop, string value)
{
    this->_sign = 1;
    this->_isOp = isop;
    this->_value = value;
}

int SToken::getSign() const{
    return (_sign);
}

string SToken::getValue() const{
    return (_value);
}

SToken &SToken::operator=(const SToken &r)
{
    this->_sign = r._sign;
    this->_isOp = r._isOp;
    this->_value = r._value;
    return (*this);
}

void SToken::setSign(int s){
    this->_sign = s;
}

void SToken::setValue(string s){
    this->_value = s;
}