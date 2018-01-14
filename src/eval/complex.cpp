#include "eval/complex.hpp"

Complex::~Complex(){}

Complex::Complex()
{
    _i = 0;
    _real = 0;
    _imag = 0;
}

Complex::Complex(string cn)
{
    _i = 0;
    _real = 0;
    _imag = 0;
    tocomplex(cn);
}

double Complex::getI() const{
    return (_i);
}

double Complex::getReal() const{
    return (_real);
}

double Complex::getImag() const{
    return (_imag);
}

Complex &Complex::operator/(const Complex &r)
{
    Complex c;

    c._real = ((_real * r._real) + (_imag * r._imag)) / ((r._real * r._real) + (r._imag * r._imag));
    c._imag = ((_imag * r._real) - (_real * r._imag)) / ((r._real * r._real) + (r._imag * r._imag));
    _real = c._real;
    _imag = c._imag;
    return (*this);
}

Complex &Complex::operator+(const Complex &r)
{
    _real += r._real;
    _imag += r._imag;
    return (*this);
}

Complex &Complex::operator*(const Complex &r)
{
    Complex c;

    c._real = (_real * r._real) - (_imag * r._imag);
    c._imag = (_real * r._imag) + (_imag * r._real);
    _real = c._real;
    _imag = c._imag;
    return (*this);
}

Complex &Complex::operator^(const Complex &r)
{
    int exp;
    int sign = 1;

    exp = r.getReal();
    if (exp % 4 == 0)
    {
        _i = 0;
        for (; exp > 1; exp--)
            *this = *this * *this;
    }
    else if (exp % 2 == 0 && exp % 4 != 0)
    {
        _i = 0;
        for (; exp > 1; exp--)
            *this = *this * *this;
        _imag *= -1;
    }
    else if ((exp - 1) % 2 == 0)
    {
        _i = 1;
        for (; exp > 1; exp--)
            *this = *this * *this;
        _imag *= -1;
    }
    else if ((exp - 1) % 4 == 0)
    {
        _i = 1;
        for (; exp > 1; exp--)
            *this = *this * *this;
    }
    return (*this);
}

void Complex::tocomplex(string cn)
{
    vector<string> cm;

    if (isnumber(cn))
        _real = stod(cn);
    else if (iscomplex(cn))
    {
        _i = 1;
        if (isnumber(string(1, cn[0])))
            _imag = stod(cn);
        else
            _imag = 1;
    }
}

void Complex::print_cn()
{
    if (_real != 0)
    {
        if (_i == 0) _real += _imag;
        cout << _real;
        if (_imag > 0)
        {
            if (_i == 1)
                cout << " + " << _imag << "i" ;
        }
        else if (_imag != 0)
        {
            if (_i == 1)
                cout << " - " << (_imag * -1) << "i";
        }
        cout << endl;
    }
    else
    {
        if (_imag != 0)
        {
            if (_i == 1)
                cout << _imag << "i" << endl;
        }
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