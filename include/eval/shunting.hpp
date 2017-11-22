#ifndef SHUNTING_HPP
#define SHUNTING_HPP

#include "common.hpp"
#include "eval/btree.hpp"
#include "eval/stoken.hpp"

class Shunting{
    public:
        stack<SToken> shuntingYard(Maps t);
};

#endif