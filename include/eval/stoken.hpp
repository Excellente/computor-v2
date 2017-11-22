#ifndef STOKEN_HPP
#define STOKEN_HPP

#include "common.hpp"

class SToken{
    bool _isOp;
    string _value;

    public:
        ~SToken();
        SToken(bool b = false, string v = "");
        
        string getValue() const;
        SToken &operator=(const SToken &r);
};

#endif