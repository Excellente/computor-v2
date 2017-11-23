#ifndef STOKEN_HPP
#define STOKEN_HPP

#include "common.hpp"

class SToken{
    int _sign;
    bool _isOp;
    string _value;

    public:
        ~SToken();
        SToken(bool b = false, string v = "");
        
        int getSign() const;
        string getValue() const;
        SToken &operator=(const SToken &r);

        void setSign(int s);
};

#endif