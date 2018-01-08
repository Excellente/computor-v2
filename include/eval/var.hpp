#ifndef VAR_HPP
#define VAR_HPP

#include "common.hpp"

template <class T>
class Variable{
    T _value;
    string _type;

    public:
        Variable();
        ~Variable();
        T operator+(const Variable &r);
        T operator-(const Variable &r);
        T operator*(const Variable &r);
        T operator/(const Variable &r);
        Variable &operator=(const Variable &r);
};

#endif