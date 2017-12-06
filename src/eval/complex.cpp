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

Complex &Complex::operator^(const Complex &r)
{
    double _2bi;
    int d = r._real;
    double _nimag = _imag;
    double _nreal = _real;

    for (int i = r._real; i > 1; i--)
    {
        if (d % 2 == 0)
            _2bi = (_imag * _nimag) * -1;
        else
            _2bi = (_imag * _nimag);
        _nreal = (_real * _nreal) + _2bi;
        _nimag = 2 * _nimag * _nreal;
    }
    _imag = _nimag;
    _real = _nreal;
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

void Complex::print_cn() const
{
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

string Complex::tostring() const
{
    string str = "";

    if (_real != 0)
    {
        str += to_string(_real);
        if (_imag > 0)
            str += " + " + to_string(_imag) + "i" ;
        else if (_imag != 0)
            str += " - " + to_string(_imag * -1) + "i";
    }
    else
    {
        if (_imag != 0)
            str += to_string(_imag) + "i";
        else
            str += "0";
    }
    return (str);
}