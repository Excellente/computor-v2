#include "eval/complex.hpp"

Complex::~Complex(){}

Complex::Complex()
{
    _real = 0;
    _imag = 0;
}

Complex::Complex(string cn)
{
    _real = 0;
    _imag = 0;
    tocomplex(cn);
}

double Complex::getReal() const{
    return (_real);
}

double Complex::getImag() const{
    return (_imag);
}

Complex &Complex::operator+(const Complex &r)
{
    _real += r._real;
    _imag += r._imag;
    return (*this);
}

Complex &Complex::operator*(const Complex &r)
{
    _real *= r._real;
    _imag *= r._imag;
    return (*this);
}

void Complex::tocomplex(string cn)
{
    vector<string> cm;

    if (isnumber(cn))
        _real = stod(cn);
    else if (iscomplex(cn))
    {
        if (isnumber(string(1, cn[0])))
            _imag = stod(cn);
        else
            _imag = 1;
    }
}

void Complex::print_cn() const{
    if (_real != 0)
    {
        cout << _real;
        if (_imag > 0)
            cout << " + " << _imag << "i" ;
        else if (_imag != 0)
            cout << " - " << (_imag * -1) << "i";
        cout << endl;
    }
    else
    {
        if (_imag != 0)
            cout << _imag << "i" << endl;
        else
            cout << 0 << endl;
    }
}