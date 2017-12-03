#ifndef SHUNTING_HPP
#define SHUNTING_HPP

#include "common.hpp"
#include "eval/btree.hpp"
#include "eval/stoken.hpp"

void print_stack(stack<SToken> st);

class Shunting{
    public:
        stack<SToken> shuntingYard(Maps);

        void print(stack<SToken>);
        void assembly_float(string &, Maps &);
        void _token_sign(string &, int &, int &);
        void assembly_matrix_multi(string &, Maps &);
        void assembly_complex(string &, Maps &, SToken &, stack<SToken> &);
};

#endif