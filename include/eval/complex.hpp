#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include "common.hpp"

class Complex{
    private:
        double _i;
        double _real;
        double _imag;

    public:
        ~Complex();
        Complex();
        Complex(string);

        double getI() const;
        double getReal() const;
        double getImag() const;
        string tostring() const;
        Complex &operator+(const Complex &r);
        Complex &operator*(const Complex &r);
        Complex &operator/(const Complex &r);
        Complex &operator^(const Complex &r);

        void print_cn();
        void tocomplex(string);
};

#endif