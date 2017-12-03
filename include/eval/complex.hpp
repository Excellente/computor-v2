#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include "common.hpp"

class Complex{
    private:
        double _real;
        double _imag;

    public:
        ~Complex();
        Complex();
        Complex(string);

        double getReal() const;
        double getImag() const;
        Complex &operator+(const Complex &r);
        Complex &operator*(const Complex &r);

        void print_cn() const;
        void tocomplex(string);
};

#endif