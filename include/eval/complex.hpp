#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include "common.hpp"

class Complex{
    private:
        double _real;
        double _imag;
    
    public:
        Complex();
        ~Complex();
        
        double getReal() const;
        double getImag() const;
};

#endif