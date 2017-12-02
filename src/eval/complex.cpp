#include "eval/complex.hpp"

Complex::Complex(){}
Complex::~Complex(){}

double Complex::getReal() const{
    return (_real);
}

double Complex::getImag() const{
    return (_imag);
}