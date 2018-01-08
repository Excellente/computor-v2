#include "eval/var.hpp"

template <class T>
Variable<T>::~Variable(){}

template <class T>
Variable<T>::Variable(){
    _type = "";
}

template <class T>
T Variable<T>::operator+(const Variable &r){
    return (_value + r._value);
}

template <class T>
T Variable<T>::operator-(const Variable &r){
    return (_value - r._value);
}

template <class T>
T Variable<T>::operator*(const Variable &r){
    return (_value * r._value);
}

template <class T>
T Variable<T>::operator/(const Variable &r){
    return (_value / r._value);
}

template <class T>
Variable<T> &Variable<T>::operator=(const Variable &r)
{
    _type = r._type;
    _value = r._value;
    return (*this);
}